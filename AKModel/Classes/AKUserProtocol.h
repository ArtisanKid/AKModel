//
//  AKUserProtocol.h
//  Pods
//
//  Created by 李翔宇 on 15/11/25.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AKUserProtocol <NSObject, NSCoding>

@required

@property (nonatomic, strong) NSString *userID;

/**
 *  OAuth模式下使用openID
 *  OAuth模式下userID总是等于openID
 */
@property (nonatomic, strong) NSString *openID;

/**
 * 用户权限
 */
@property (nonatomic, assign) NSUInteger role;

@property (nonatomic, copy) NSString *portrait;/**<头像*/
@property (nonatomic, copy) NSString *smallPortrait;/**<小头像，主要用于IM，通知等*/
@property (nonatomic, copy) NSString *largePortrait;/**<大头像*/

@property (nonatomic, strong) NSString *nickName;/**<昵称*/
@property (nonatomic, strong) NSString *realName;/**<用户名*/

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
@property (nonatomic, assign, getter = isLogined) BOOL logined;

/**
 *  注册Log状态
 *
 *  @param target id
 *  @param block  void(^)(BOOL isLogined)
 */
+ (void)registerDelegate:(id)target loginStateChanged:(void(^)(id target, BOOL isLogined))block;

/**
 *  此属性内部维护即可
 *  NSDictionary<Target, block>
 */
//@property(nonatomic, strong) NSMapTable<id, void(^)(BOOL isLogined)> *registerTable;

@end

NS_ASSUME_NONNULL_END
