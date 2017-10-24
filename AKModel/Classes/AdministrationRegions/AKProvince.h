//
//  AKProvince.h
//  Pods
//
//  Created by 李翔宇 on 2017/7/31.
//
//

//省级行政单位

#import <Foundation/Foundation.h>
#import "AKCity.h"

typedef NS_ENUM(NSUInteger, AKProvinceType) {
    AKProvinceTypeDefault,//省
    AKProvinceTypeAutonomousRegion,//自治区
    AKProvinceTypeMunicipality,//直辖市
    AKProvinceTypeSpecialAdministrativeRegion,//特别行政区
};

NS_ASSUME_NONNULL_BEGIN

@interface AKProvince : NSObject

@property (nonatomic, copy) NSString *provinceID;/**<省ID*/
@property (nonatomic, copy) NSString *cName;/**<中文名*/
@property (nonatomic, copy) NSString *spell;/**<拼音*/
@property (nonatomic, copy) NSString *eName;/**<英文名*/

@property (nonatomic, assign ) AKProvinceType type;/**<类型*/

@property (nonatomic, copy) NSArray<AKCity *> *cities;

@end

NS_ASSUME_NONNULL_END
