//
//  AKSettings.h
//  Pods
//
//  Created by 李翔宇 on 2017/8/1.
//
//

//应用设置集合，与用户无关

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AKSettings : NSObject

@property (nonatomic, assign, getter=isAllowPush) BOOL allowPush;

@end

NS_ASSUME_NONNULL_END
