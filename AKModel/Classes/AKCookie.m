//
//  AKCookie.m
//  Pods
//
//  Created by 李翔宇 on 16/8/17.
//
//

#import "AKCookie.h"
#import "AKCoding.h"

@implementation AKCookie

+ (AKCookie *)currentCookie {
    static AKCookie *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if(!(sharedInstance = [self readSingleton])) {
            sharedInstance = [[super allocWithZone:NULL] init];
        }
        [sharedInstance startKVO];
    });
    return sharedInstance;
}

AKCoding

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSString *,id> *)change context:(void *)context {
    [self cacheSingleton];
}

#pragma mark- 协议方法
@synthesize valid = _valid;

- (void)setValid:(BOOL)valid {
    if(_valid == valid) {
        return;
    }
    
    if(valid) {
        [self willChangeValueForKey:@"valid"];
        _valid = valid;
        [self willChangeValueForKey:@"valid"];
    } else {
        _valid = valid;
        [self clearUp];
        [self cacheSingleton];
    }
}

- (BOOL)isValid {
    //数据缺失情况下认为是不合法
    if (!self.zTicket.length || 
        !self.expireTimestamp ||
        self.expireTimestamp < [NSDate date].timeIntervalSince1970) {
        self.valid = NO;
    }
    return _valid;
}

@end
