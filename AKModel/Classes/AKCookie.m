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
        [sharedInstance.observedKeyPathsM removeAllObjects];
        [sharedInstance registerKVO:@"zTicket", @"expiredTime", @"valid", @"unexpired", nil];
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
}

- (BOOL)isValid {
    //数据缺失情况下认为是不合法
    if (!self.zTicket.length || 
        !self.expiredTime) {
        _valid = NO;
    }
    return _valid;
}

@synthesize unexpired = _unexpired;

- (BOOL)isUnexpired {
    if (self.expiredTime < [NSDate date].timeIntervalSince1970) {
        _unexpired = NO;
    }
    return _unexpired;
}

@end
