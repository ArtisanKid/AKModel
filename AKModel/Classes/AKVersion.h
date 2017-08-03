//
//  AKVersion.h
//  Pods
//
//  Created by 李翔宇 on 2017/2/14.
//
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AKVersionType) {
    AKVersionTypeMajor,
    AKVersionTypeMinor,
    AKVersionTypePatch,
};

NS_ASSUME_NONNULL_BEGIN

@interface AKVersion : NSObject

/// 版本ID
@property (nonatomic, copy) NSString *versionID;

/// 更新类型
@property (nonatomic, assign) AKVersionType type;

/// 发布版本 x.y.z
@property (nonatomic, copy) NSString *releaseVersion;

/// 构建版本 x.y.z
@property (nonatomic, copy) NSString *buildVersion;

/// 发布时间戳
@property (nonatomic, assign) NSTimeInterval releaseTimestamp;

/// 是否强制升级
@property (nonatomic, assign, getter=isForceUpdate) BOOL forceUpdate;

/// 是否弹窗提示
@property (nonatomic, assign, getter=isAlert) BOOL alert;

/// 弹窗提示信
@property (nonatomic, copy) NSString *message;

/// 资源地址
@property (nonatomic, copy) NSString *URLStr;

@end

NS_ASSUME_NONNULL_END
