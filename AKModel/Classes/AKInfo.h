//
//  AKInfo.h
//  Pods
//
//  Created by 李翔宇 on 2017/8/1.
//
//

//应用信息集合，与用户无关
//只包含业务级信息

#import <Foundation/Foundation.h>
#import "AKVersion.h"

NS_ASSUME_NONNULL_BEGIN

@interface AKInfo : NSObject

@property (nonatomic, strong) AKVersion *version;

@property (nonatomic, copy) NSString *statement;/**<声明*/
@property (nonatomic, copy) NSString *about;/**<关于*/

@end

NS_ASSUME_NONNULL_END
