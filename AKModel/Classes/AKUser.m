//
//  AKUser.m
//  Pods
//
//  Created by 李翔宇 on 15/11/23.
//
//

#import "AKUser.h"
#import <libkern/OSAtomic.h>
#import "AKCoding.h"

@interface AKUser ()

@property (nonatomic, strong) NSMapTable *delegateTable;

@end

@implementation AKUser

#pragma mark- 创建锁
static OSSpinLock AKUser_Lock = OS_SPINLOCK_INIT;

+ (AKUser *)currentUser {
    static AKUser *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if(!(sharedInstance = [self readSingleton])) {
            sharedInstance = [[super allocWithZone:NULL] init];
        }
        [sharedInstance registerKVO];
    });
    return sharedInstance;
}

- (void)registerKVO {
    [self.observedKeyPathsM removeAllObjects];
    [self registerKVO:@"visitorID", @"userID", @"openID", @"role", @"portrait", @"smallPortrait", @"largePortrait", @"nickName", @"realName", @"gender", @"mobile", @"tel", @"email", @"address", @"brief", @"detail", @"loginType", @"logined", nil];
}

AKCoding

#pragma mark- 私有方法
- (NSMapTable *)delegateTable {
    static NSMapTable<id, NSMutableArray<void(^)(id target, BOOL isLogined)> *> *registerTable = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        registerTable = [NSMapTable weakToStrongObjectsMapTable];
    });
    return registerTable;
}

#pragma mark- 协议方法
- (NSString *)userID {
    if(!_userID.length) {
        return self.openID;
    }
    return _userID;
}

- (void)setLogined:(BOOL)logined {
    if(_logined == logined) {
        return;
    }
    
    //[self willChangeValueForKey:@"logined"];
    _logined = logined;
    //[self didChangeValueForKey:@"logined"];
    
    if(!_logined) {
        [self clearUp];
    }

    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        OSSpinLockLock(&AKUser_Lock);
        NSEnumerator *enumerator = self.delegateTable.keyEnumerator;
        id target = nil;
        while ((target = enumerator.nextObject)) {
            NSArray *blocksI = [[self.delegateTable objectForKey:target] copy];
            [blocksI enumerateObjectsUsingBlock:^(void (^ _Nonnull block)(id, BOOL), NSUInteger idx, BOOL * _Nonnull stop) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    if (block) {
                        block(target, _logined);
                    }
                });
            }];
        }
        OSSpinLockUnlock(&AKUser_Lock);
    });
}

+ (void)registerDelegate:(id)target loginStateChanged:(void(^)(id target, BOOL isLogined))block {
    if(!target || !block) {
        return;
    }
    OSSpinLockLock(&AKUser_Lock);
    
    NSMutableArray *blocksM = [self.currentUser.delegateTable objectForKey:target];
    if(!blocksM) {
        blocksM = NSMutableArray.array;
        [self.currentUser.delegateTable setObject:blocksM forKey:target];
    }
    [blocksM addObject:block];
    
    OSSpinLockUnlock(&AKUser_Lock);
}

@end
