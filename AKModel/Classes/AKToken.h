//
//  AKToken.h
//  Pods
//
//  Created by 李翔宇 on 16/6/12.
//
//

#import "AKModel.h"
#import "AKTokenProtocol.h"

typedef NS_ENUM(NSUInteger, AKTokenState) {
    AKTokenStateNormal,
    AKTokenStateRefreshing
};

NS_ASSUME_NONNULL_BEGIN

@interface AKToken : AKModel<AKTokenProtocol>

@property (class, nonatomic, strong, readonly) AKToken *currentToken;/**<当前token*/

@property (nonatomic, copy) NSString *accessToken;
@property (nonatomic, copy) NSString *refreshToken;

@property (nonatomic, assign) NSTimeInterval expireTimestamp;/**<过期时间*/
@property (nonatomic, assign, getter=isValid) BOOL valid;/**<是否有效*/
@property (nonatomic, assign, getter=isUnexpired) BOOL unexpired;/**<是否过期*/

@end

NS_ASSUME_NONNULL_END
