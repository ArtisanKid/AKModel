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

@property (nonatomic, copy) NSString *accessToken;
@property (nonatomic, copy) NSString *refreshToken;

@property (nonatomic, assign) NSTimeInterval expireTimestamp;/**<过期时间*/
@property (nonatomic, assign, getter=isValid) BOOL valid;/**<是否有效*/
@property (nonatomic, assign, getter=isUnexpired) BOOL unexpired;/**<是否过期*/
@property (nonatomic, assign) NSTimeInterval timestamp;/**<最后操作的时间戳*/

@end

NS_ASSUME_NONNULL_END
