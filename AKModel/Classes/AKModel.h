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

- (void)registerKVO:(NSString *)firstKey, ... NS_REQUIRES_NIL_TERMINATION;
- (void)unregisterKVO:(NSString *)firstKey, ... NS_REQUIRES_NIL_TERMINATION;

- (void)startKVO;
- (void)stopKVO;

- (void)clearUp;

- (void)cacheSingleton;
- (void)cacheWithSignature:(NSString *)signature;

+ (id)readSingleton;
+ (id)readWithSignature:(NSString *)signature;

@end

NS_ASSUME_NONNULL_END
