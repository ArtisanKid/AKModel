//
//  AKTokenProtocol.h
//  Pods
//
//  Created by 李翔宇 on 16/8/17.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AKTokenProtocol <NSObject>

@required

/**
 *  用户的accessToken
 */
@property (nonatomic, copy) NSString *accessToken;

/**
 *  用于刷新accessToken的refreshToken
 */
@property (nonatomic, copy) NSString *refreshToken;

/**
 * 过期时间
 */
@property (nonatomic, assign) NSTimeInterval expireTimestamp;

/**
 * 类型 bear/basic
 */
@property (nonatomic, copy) NSString *type;

/**
 *  是否有效
 */
@property (nonatomic, assign, getter=isValid) BOOL valid;

/**
 *  是否过期，YES未过期
 */
@property (nonatomic, assign, getter=isUnexpire) BOOL unexpire;

/**
 *  最后操作的时间戳
 */
@property (nonatomic, assign) NSTimeInterval timestamp;

/**
 *  最后操作的时间戳
 */
@property (nonatomic, assign) NSUInteger state;

@end

NS_ASSUME_NONNULL_END
