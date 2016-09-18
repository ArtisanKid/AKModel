//
//  AKUser.h
//  Pods
//
//  Created by 李翔宇 on 15/11/23.
//
//

#import <Foundation/Foundation.h>
#import "AKUserProtocol.h"
#import <AKSingleton/AKSingleton.h>

NS_ASSUME_NONNULL_BEGIN

@interface AKUser : NSObject<AKUserProtocol>

@property (nonatomic, strong) NSString *userID;

/**
 *  OAuth模式下使用openID
 *  OAuth模式下userID总是等于openID
 */
@property (nonatomic, strong) NSString *openID;

/**
 *  游客ID
 */
+ (NSString *)visitorID;
+ (void)setVisitorID:(NSString *)visitorID;

/**
 * 用户权限
 */
@property (nonatomic, assign) NSUInteger role;

@property (nonatomic, copy) NSString *portrait;/**<头像*/
@property (nonatomic, copy) NSString *smallPortrait;/**<小头像，主要用于IM，通知等*/
@property (nonatomic, copy) NSString *largePortrait;/**<大头像*/

@property (nonatomic, strong) NSString *nickName;
@property (nonatomic, strong) NSString *realName;

@property (nonatomic, assign) NSUInteger gender;/**<性别*/

@property (nonatomic, strong) NSString *mobile;
@property (nonatomic, strong) NSString *tel;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *address;

@property (nonatomic, strong) NSString *brief;
@property (nonatomic, strong) NSString *detail;

/**
 *  登陆类型
 */
@property (nonatomic, assign) NSUInteger loginType;

/**
 *  是否已经登陆
 */
- (void)setLogined:(BOOL)logined;
- (BOOL)isLogined;

/**
 *  注册Log状态
 *  内部使用NSMapTable(weak->strong)来管理(target，blocks)，使用此方法的原因是，无需主动释放target。根据文档说明，当key释放的时候，NSMapTable中对应的value也会释放(延迟的)。
    但是需要注意的是，因为blocks是strong类型，调用self仍然会发生循环引用(User->NSMapTable->blocks->self)。
    解决方法
    (1)weakfy,strongfy
    (2)使用block中的target
 *
 *  @param target id
 *  @param block  void(^)(BOOL isLogined)
 */
+ (void)registerDelegate:(id)target loginStateChanged:(void(^)(id target, BOOL isLogined))block;

AKSingletonHeader(AKUser, currentUser);

@end

NS_ASSUME_NONNULL_END
