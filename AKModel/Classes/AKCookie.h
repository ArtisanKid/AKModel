//
//  AKCookie.h
//  Pods
//
//  Created by 李翔宇 on 16/8/17.
//
//

#import <Foundation/Foundation.h>
#import <AKSingleton/AKSingleton.h>
#import "AKCookieProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface AKCookie : NSObject

/**
 *  用户的zTicket
 */
@property (nonatomic, copy) NSString *zTicket;

/**
 * 过期时间
 */
@property (nonatomic, assign) NSTimeInterval expireTimestamp;

/**
 *  是否有效
 */
@property (nonatomic, assign, getter=isValid) BOOL valid;

/**
 *  是否过期，YES未过期
 */
@property (nonatomic, assign, getter=isUnexpire) BOOL unexpire;

AKSingletonHeader(AKCookie, currentCookie);

@end

NS_ASSUME_NONNULL_END
