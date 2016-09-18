//
//  AKToken.m
//  Pods
//
//  Created by 李翔宇 on 16/6/12.
//
//

#import "AKToken.h"
#import "AKCoding.h"
#import <AKSingleton/AKSingletonCache.h>

@interface AKToken ()

@property (nonatomic, assign) BOOL innerValid;
@property (nonatomic, assign) BOOL innerUnexpire;

@end

@implementation AKToken

AKCoding
AKSingletonCache(AKToken, currentToken, _accessToken, _refreshToken, _expireTimestamp, _type, _innerValid, _innerUnexpire)

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
    if (!self.accessToken.length || 
        !self.refreshToken.length || 
        !self.expireTimestamp || 
        !self.type.length) {
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
