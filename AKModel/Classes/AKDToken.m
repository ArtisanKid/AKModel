//
//  AKToken.m
//  Pods
//
//  Created by 李翔宇 on 16/6/12.
//
//

#import "AKDToken.h"
#import "AKCoding.h"

@implementation AKDToken

+ (AKDToken *)currentToken {
    static AKDToken *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if(!(sharedInstance = [self readSingleton])) {
            sharedInstance = [[super allocWithZone:NULL] init];
        }
        [sharedInstance registerKVO:@"accessToken", @"refreshToken", @"expiredTime", nil];
    });
    return sharedInstance;
}

AKCoding

#pragma mark- 协议方法
@synthesize valid = _valid;

- (void)setValid:(BOOL)valid {
    if(_valid == valid) {
        return;
    }
    
    _valid = valid;
    
    if(!_valid) {
        [self clearUp];
    }
    [self cacheSingleton];
}

- (BOOL)isValid {
    //数据缺失情况下认为是不合法
    if (!self.accessToken.length || 
        !self.refreshToken.length || 
        !self.expiredTime) {
        self.valid = NO;
    }
    return _valid;
}

@synthesize unexpired = _unexpired;

- (void)setUnexpired:(BOOL)unexpired {
    if(_unexpired == unexpired) {
        return;
    }
    
    _unexpired = unexpired;
    [self cacheSingleton];
}


- (BOOL)isUnexpired {
    if (self.expiredTime < [NSDate date].timeIntervalSince1970) {
        self.unexpired = NO;
    }
    return _unexpired;
}

@end
