//
//  AKCookieProtocol.h
//  Pods
//
//  Created by 李翔宇 on 16/8/17.
//
//

#import <Foundation/Foundation.h>

@protocol AKCookieProtocol <NSObject>

@property (nonatomic, copy) NSString *zTicket;
@property (nonatomic, assign) NSTimeInterval expireTimestamp;/**<过期时间*/
@property (nonatomic, assign, getter=isValid) BOOL valid;/**<是否有效*/

@end
