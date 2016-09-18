//
//  AKCookie.m
//  Pods
//
//  Created by 李翔宇 on 16/8/17.
//
//

#import "AKCookie.h"
#import "AKCoding.h"
#import <AKSingleton/AKSingletonCache.h>

@interface AKCookie ()

@property (nonatomic, assign) BOOL innerValid;
@property (nonatomic, assign) BOOL innerUnexpire;

@end

@implementation AKCookie

AKCoding
AKSingletonCache(AKCookie, currentCookie, _zTicket, _expireTimestamp, _innerValid, _innerUnexpire)

#pragma mark- 协议方法

- (void)setValid:(BOOL)valid {
    if(self.innerValid == valid) {
        return;
    }
    
    self.innerValid = valid;
    self.unexpire = self.innerValid;
}

- (BOOL)isValid {
    //数据缺失情况下认为是不合法
    if (!self.zTicket.length || 
        !self.expireTimestamp) {
        if(self.innerValid) {
            _innerValid = NO;
            [self cache];
        }
    }
    return self.innerValid;
}

- (void)setUnexpire:(BOOL)unexpire {
    if(self.innerUnexpire == unexpire) {
        return;
    }
    
    self.innerUnexpire = unexpire;
}

- (BOOL)isUnexpire {
    if (self.expireTimestamp - NSDate.date.timeIntervalSince1970 < 60) {
        if(self.innerUnexpire) {
            _innerUnexpire = NO;
            [self cache];
        }
    }
    return self.innerUnexpire;
}

@end
