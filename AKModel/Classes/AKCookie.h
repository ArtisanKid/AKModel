//
//  AKCookie.h
//  Pods
//
//  Created by 李翔宇 on 16/8/17.
//
//

#import "AKModel.h"
#import "AKCookieProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface AKCookie : AKModel

@property (class, nonatomic, strong, readonly) AKCookie *currentCookie;/**<当前cookie*/

@property (nonatomic, copy) NSString *zTicket;
@property (nonatomic, assign) NSTimeInterval expireTimestamp;/**<过期时间*/
@property (nonatomic, assign, getter=isValid) BOOL valid;/**<是否有效*/

@end

NS_ASSUME_NONNULL_END
