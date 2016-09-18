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
#import <AKSingleton/AKSingletonCache.h>

@interface AKUser ()

@property (nonatomic, assign) BOOL innerLogined;

@end

@implementation AKUser

#pragma mark- 创建锁
static OSSpinLock AKUser_Lock = OS_SPINLOCK_INIT;

AKCoding
AKSingletonCache(AKUser, currentUser, _userID, _openID, _role, _portrait, _smallPortrait, _largePortrait, _nickName, _realName, _gender, _mobile, _tel, _email, _address, _brief, _detail)

#pragma mark- 私有方法
- (NSMapTable *)registerTable {
    static NSMapTable<id, NSMutableArray<void(^)(id target, BOOL isLogined)> *> *registerTable = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        registerTable = NSMapTable.weakToStrongObjectsMapTable;
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

static NSString *AK_User_VisitorID = nil;
+ (NSString *)visitorID {
    return AK_User_VisitorID;
}

+ (void)setVisitorID:(NSString *)visitorID {
    AK_User_VisitorID = visitorID;
}

- (BOOL)isLogined {
    return _innerLogined;
}

- (void)setLogined:(BOOL)logined {
    if(_innerLogined == logined) {
        return;
    }
    
    _innerLogined = logined;
    if(_innerLogined) {
        [self cache];
    } else {
        [self clear];
    }

    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        OSSpinLockLock(&AKUser_Lock);
        NSEnumerator *enumerator = self.registerTable.keyEnumerator;
        id target = nil;
        while ((target = enumerator.nextObject)) {
            NSArray *blocksI = [[self.registerTable objectForKey:target] copy];
            [blocksI enumerateObjectsUsingBlock:^(void (^ _Nonnull block)(id, BOOL), NSUInteger idx, BOOL * _Nonnull stop) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    if (block) {
                        block(target, _innerLogined);
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
    
    NSMutableArray *blocksM = [self.currentUser.registerTable objectForKey:target];
    if(!blocksM) {
        blocksM = NSMutableArray.array;
        [self.currentUser.registerTable setObject:blocksM forKey:target];
    }
    [blocksM addObject:block];
    
    OSSpinLockUnlock(&AKUser_Lock);
}

@end
