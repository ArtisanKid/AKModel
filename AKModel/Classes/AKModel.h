//
//  AKModel.h
//  Pods
//
//  Created by 李翔宇 on 2016/12/17.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AKModel : NSObject

/**
 监听自身属性

 @param firstKeyPath 监听路径
 */
- (void)registerKVO:(NSString *)firstKeyPath, ... NS_REQUIRES_NIL_TERMINATION;

/**
 解除监听自身属性
 
 @param firstKeyPath 监听路径
 */
- (void)unregisterKVO:(NSString *)firstKeyPath, ... NS_REQUIRES_NIL_TERMINATION;

- (void)clearUp;

- (void)cacheSingleton;
- (void)cacheWithSignature:(NSString *)signature;

+ (id)readSingleton;
+ (id)readWithSignature:(NSString *)signature;

@end

NS_ASSUME_NONNULL_END
