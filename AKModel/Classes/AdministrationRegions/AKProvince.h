//
//  AKProvince.h
//  Pods
//
//  Created by 李翔宇 on 2017/7/31.
//
//

//省

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AKProvinceType) {
    /**
     河北省 · 山西省 · 辽宁省 · 吉林省 · 黑龙江省 · 江苏省 · 浙江省 · 安徽省 · 福建省 · 江西省 · 山东省 · 河南省 · 湖北省 · 湖南省 · 广东省 · 海南省 · 四川省 · 贵州省 · 云南省 · 陕西省 · 甘肃省 · 青海省 · 台湾省
     */
    AKProvinceTypeDefault,//省
    
    /**
     内蒙古自治区 · 广西壮族自治区 · 西藏自治区 · 宁夏回族自治区 · 新疆维吾尔自治区
     */
    AKProvinceTypeAutonomousRegion,//自治区
    
    /**
     北京市 · 天津市 · 上海市 · 重庆市
     */
    AKProvinceTypeMunicipality,//直辖市
    
    /**
     香港特别行政区 · 澳门特别行政区
     */
    AKProvinceTypeSpecialAdministrativeRegion,//特别行政区
};

NS_ASSUME_NONNULL_BEGIN

@interface AKProvince : NSObject

@property (nonatomic, copy) NSString *provinceID;/**<省ID*/
@property (nonatomic, copy) NSString *cName;/**<中文名*/
@property (nonatomic, copy) NSString *spell;/**<拼音*/
@property (nonatomic, copy) NSString *eName;/**<英文名*/

@property (nonatomic, assign ) AKProvinceType type;/**<类型*/

@end

NS_ASSUME_NONNULL_END
