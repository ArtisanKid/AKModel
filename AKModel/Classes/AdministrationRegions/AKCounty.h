//
//  AKCounty.h
//  Pods
//
//  Created by 李翔宇 on 2017/7/31.
//
//

//县级行政单位

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AKCountyType) {
    AKCountyTypeDefault,//县
    AKCountyTypeAutonomousCounty,//自治县
    AKCountyTypeCountyLevelCity,//县级市
    AKCountyTypeBanner,//旗
    AKCountyTypeAutonomousBanner,//自治旗
    AKCountyTypeMunicipalDistrict,//市辖区
    AKCountyTypeForestRegion,//林区
    AKCountyTypeZsar,//特区
};

NS_ASSUME_NONNULL_BEGIN

@interface AKCounty : NSObject

@property (nonatomic, copy) NSString *countyID;/**<县ID*/
@property (nonatomic, copy) NSString *cName;/**<中文名*/
@property (nonatomic, copy) NSString *spell;/**<拼音*/
@property (nonatomic, copy) NSString *eName;/**<英文名*/

@property (nonatomic, assign) AKCountyType type;/**<类型*/

@end

NS_ASSUME_NONNULL_END
