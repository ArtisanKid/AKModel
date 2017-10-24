//
//  AKCity.h
//  Pods
//
//  Created by 李翔宇 on 2017/7/31.
//
//

//市级行政单位

#import <Foundation/Foundation.h>
#import "AKCounty.h"

typedef NS_ENUM(NSUInteger, AKCityType) {
    AKCityTypeDefault,//市
    AKCityTypePrefecture,//地区
    AKCityTypeAutonomousPrefecture,//自治州*/
    AKCityTypeLeague,//盟
};

NS_ASSUME_NONNULL_BEGIN

@interface AKCity : NSObject

@property (nonatomic, copy) NSString *cityID;/**<城市ID*/
@property (nonatomic, copy) NSString *cName;/**<中文名*/
@property (nonatomic, copy) NSString *spell;/**<拼音*/
@property (nonatomic, copy) NSString *eName;/**<英文名*/

@property (nonatomic, assign ) AKCityType type;/**<类型*/

@property (nonatomic, copy) NSArray<AKCounty *> *counties;

@end

NS_ASSUME_NONNULL_END
