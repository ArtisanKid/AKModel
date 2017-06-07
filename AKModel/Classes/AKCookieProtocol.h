//
//  AKCookieProtocol.h
//  Pods
//
//  Created by 李翔宇 on 16/8/17.
//
//

#import <Foundation/Foundation.h>

@protocol AKCookieProtocol

@property (nonatomic, copy) NSString *zTicket;
@property (nonatomic, assign) NSTimeInterval expiredTime;/**<过期时间*/
@property (nonatomic, assign, getter=isValid) BOOL valid;/**<数据是否有效*/

@end
