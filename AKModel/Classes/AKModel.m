//
//  AKModel.m
//  Pods
//
//  Created by 李翔宇 on 2016/12/17.
//
//

#import "AKModel.h"
#import <objc/runtime.h>
#import "AKModelMacro.h"

@interface AKModel ()

@property (nonatomic, strong) NSMutableSet *kvoKeysM;

@end

@implementation AKModel

- (void)registerKVO:(NSString *)firstKey, ... {
    NSString *key = firstKey;
    va_list argList;
    va_start(argList, firstKey);
    do {
        if(![key isKindOfClass:[NSString class]]) {
            return;
        }
        
        if(!key.length) {
            return;
        }
        
        if([self.kvoKeysM containsObject:key]) {
            return;
        }
        
        [self.kvoKeysM addObject:key];
        [self addObserver:self forKeyPath:key options:NSKeyValueObservingOptionNew context:NULL];
    } while (key = va_arg(argList, id));
    va_end(argList);
}

- (void)unregisterKVO:(NSString *)firstKey, ... {
    NSString *key = firstKey;
    va_list argList;
    va_start(argList, firstKey);
    do {
        if(![key isKindOfClass:[NSString class]]) {
            return;
        }
        
        if(!key.length) {
            return;
        }
        
        if(![self.kvoKeysM containsObject:key]) {
            return;
        }
        
        [self.kvoKeysM removeObject:key];
        [self removeObserver:self forKeyPath:key];
    } while (key = va_arg(argList, id));
    va_end(argList);
}

- (void)startKVO {
    [self.kvoKeysM addObjectsFromArray:[[self class] customPropertyNames]];
    [self resumeKVO];
}

- (void)stopKVO {
    [self pauseKVO];
    [self.kvoKeysM removeAllObjects];
}

- (void)clearUp {
    [self pauseKVO];
    [[self.kvoKeysM copy] enumerateObjectsUsingBlock:^(NSString * _Nonnull key, NSUInteger idx, BOOL * _Nonnull stop) {
        id object = [self valueForKey:key];
        if([object isKindOfClass:[NSValue class]]) {
            [self setValue:sjb_nilValue(object) forKey:key];
        } else {
            [self setValue:nil forKey:key];
        }
    }];
    [self resumeKVO];
}

- (void)cacheSingleton {
    [self cacheWithSignature:[[self class] defaultSignature]];
}

- (void)cacheWithSignature:(NSString *)signature {
    NSString *folderPath = [[self class] modelFolderPath];
    [self cacheToFolderPath:folderPath signature:signature];
}

- (void)cacheToFolderPath:(NSString *)folderPath signature:(NSString *)signature {
    Class class = [self class];
    AKModelLog(@"缓存%@对象", NSStringFromClass(class));
    if(![self conformsToProtocol:@protocol(NSCoding)]) {
        AKModelLog(@"%@未实现NSCoding协议", NSStringFromClass(class));
        return;
    }
    
    NSError *error = nil;
    if(![NSFileManager.defaultManager createDirectoryAtPath:folderPath withIntermediateDirectories:YES attributes:nil error:&error]) {
        if(error) {
            AKModelLog(@"创建目录错误 error:%@", error);
        } else {
            AKModelLog(@"创建目录未知错误");
        }
        return;
    }
    
    NSString *path = [[self class] modelPathWithFolderPath:folderPath signature:signature];
    [NSKeyedArchiver archiveRootObject:self toFile:path];
}

+ (id)readSingleton {
    return [self readWithSignature:[self defaultSignature]];
}

+ (id)readWithSignature:(NSString *)signature {
    NSString *folderPath = [self modelFolderPath];
    return [self readFromFolderPath:folderPath signature:signature];
}

+ (id)readFromFolderPath:(NSString *)folderPath signature:(NSString *)signature {
    Class class = [self class];
    AKModelLog(@"缓存%@对象", NSStringFromClass(class));
    if(![self conformsToProtocol:@protocol(NSCoding)]) {
        AKModelLog(@"%@未实现NSCoding协议", NSStringFromClass(class));
        return nil;
    }
    
    NSString *path = [self modelPathWithFolderPath:folderPath signature:signature];
    return [NSKeyedUnarchiver unarchiveObjectWithFile:path];
}

#pragma mark - Private Method
- (NSMutableSet *)kvoKeysM {
    if(_kvoKeysM) {
        return _kvoKeysM;
    }
    
    _kvoKeysM = [NSMutableSet set];
    return _kvoKeysM;
}

- (void)pauseKVO {
    [[self.kvoKeysM copy] enumerateObjectsUsingBlock:^(id  _Nonnull key, NSUInteger idx, BOOL * _Nonnull stop) {
        [self removeObserver:self forKeyPath:key];
    }];
}

- (void)resumeKVO {
    [[self.kvoKeysM copy] enumerateObjectsUsingBlock:^(id  _Nonnull key, NSUInteger idx, BOOL * _Nonnull stop) {
        [self addObserver:self forKeyPath:key options:NSKeyValueObservingOptionNew context:NULL];
    }];
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSString *,id> *)change context:(void *)context {
    AKModelLog(@"变更属性%@，%@", keyPath, change);
}

+ (NSMutableArray<NSString *> *)customPropertyNames {
    Class class = [self class];
    NSMutableArray *namesM = [NSMutableArray array];
    do {
        NSBundle *bundle = [NSBundle bundleForClass:class];
        if (bundle != NSBundle.mainBundle) {//非自定义类，不做监听
            return [namesM copy];
        }
        
        unsigned int propertyCount = 0;
        objc_property_t *properties = class_copyPropertyList(class, &propertyCount);
        for(int i = 0; i < propertyCount; i++) {
            objc_property_t property = properties[i];
            const char *propertyName = property_getName(property);
            NSString *key = [NSString stringWithUTF8String:propertyName];
            [namesM addObject:key];
        }
    } while ((class = [class superclass]));
    return [namesM copy];
}

+ (NSString *)defaultSignature {
    NSMutableArray<NSString *> *signatureComponents = [[self customPropertyNames] mutableCopy];
    [signatureComponents sortUsingComparator:^NSComparisonResult(id  _Nonnull obj1, id  _Nonnull obj2) {
        return [obj1 compare:obj2];
    }];
    NSString *signature = @([[signatureComponents componentsJoinedByString:@":"] hash]).description;
    return signature;
}

+ (NSString *)modelFolderPath {
    NSMutableArray *componentsM = [NSMutableArray array];
    [componentsM addObject:NSHomeDirectory()];
    [componentsM addObject:@"Library"];
    [componentsM addObject:@"AKModel"];
    [componentsM addObject:NSStringFromClass(self)];
    NSString *path = [NSString pathWithComponents:componentsM];
    return path;
}

//模型对象路径，
+ (NSString *)modelPathWithFolderPath:(NSString *)folderPath signature:(NSString *)signature {
    NSMutableArray *componentsM = [NSMutableArray array];
    [componentsM addObject:folderPath];
    NSString *fileName = [NSString stringWithFormat:@"%@-%@", NSStringFromClass([self class]), signature];
    [componentsM addObject:fileName];
    NSString *path = [NSString pathWithComponents:componentsM];
    return path;
}

NSValue * sjb_nilValue(NSValue *value) {
    NSString *type = [NSString stringWithUTF8String:value.objCType];
    if ([type isEqualToString:@"c"]) {
        return [NSNumber numberWithChar:0];//char
    } else if ([type isEqualToString:@"i"]) {
        return [NSNumber numberWithInt:0];//int
    } else if ([type isEqualToString:@"s"]) {
        return [NSNumber numberWithShort:0];//short
    } else if ([type isEqualToString:@"l"]) {
        return [NSNumber numberWithLong:0];//long
    } else if ([type isEqualToString:@"q"]) {
        return [NSNumber numberWithLongLong:0];//long long
    } else if ([type isEqualToString:@"C"]) {
        return [NSNumber numberWithUnsignedChar:0];
    } else if ([type isEqualToString:@"I"]) {
        return [NSNumber numberWithUnsignedInt:0];
    } else if ([type isEqualToString:@"S"]) {
        return [NSNumber numberWithUnsignedShort:0];
    } else if ([type isEqualToString:@"L"]) {
        return [NSNumber numberWithUnsignedLong:0];
    } else if ([type isEqualToString:@"Q"]) {
        return [NSNumber numberWithUnsignedLongLong:0];
    } else if ([type isEqualToString:@"f"]) {
        return [NSNumber numberWithFloat:0.];
    } else if ([type isEqualToString:@"d"]) {
        return [NSNumber numberWithDouble:0.];
    } else if ([type isEqualToString:@"B"]) {
        return [NSNumber numberWithBool:NO];
    }
    return nil;
}

@end
