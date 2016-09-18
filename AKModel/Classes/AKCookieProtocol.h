//
//  AKCookieProtocol.h
//  Pods
//
//  Created by 李翔宇 on 16/8/17.
//
//

#import <Foundation/Foundation.h>

@protocol AKCookieProtocol <NSObject>

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

@end
