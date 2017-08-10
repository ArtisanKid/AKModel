//
//  AKCity.h
//  Pods
//
//  Created by 李翔宇 on 2017/7/31.
//
//

//市

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AKCityType) {
    AKCityTypeDefault,//市
    
    /**
     地区名称	        所属省级行政区
     大兴安岭地区	    黑龙江省
     那曲地区	        西藏自治区
     阿里地区	        西藏自治区
     阿克苏地区	    新疆维吾尔自治区
     喀什地区	        新疆维吾尔自治区
     和田地区	        新疆维吾尔自治区
     塔城地区	        新疆维吾尔自治区
     阿勒泰地区	    新疆维吾尔自治区
     */
    AKCityTypePrefecture,//地区
    
    /**
     所属省份	名称
     甘肃省	临夏回族自治州
     甘肃省	甘南藏族自治州
     贵州省	黔东南苗族侗族自治州
     贵州省	黔南布依族苗族自治州
     贵州省	黔西南布依族苗族自治州
     湖北省	恩施土家族苗族自治州
     湖南省	湘西土家族苗族自治州
     吉林省	延边朝鲜族自治州
     青海省	海北藏族自治州
     青海省	海南藏族自治州
     青海省	黄南藏族自治州
     青海省	果洛藏族自治州
     青海省	玉树藏族自治州
     青海省	海西蒙古族藏族自治州
     四川省	阿坝藏族羌族自治州
     四川省	甘孜藏族自治州
     四川省	凉山彝族自治州
     新疆维吾尔自治区	克孜勒苏柯尔克孜自治州
     新疆维吾尔自治区	博尔塔拉蒙古自治州
     新疆维吾尔自治区	昌吉回族自治州
     新疆维吾尔自治区	巴音郭楞蒙古自治州
     新疆维吾尔自治区	伊犁哈萨克自治州
     云南省	德宏傣族景颇族自治州
     云南省	怒江傈僳族自治州
     云南省	迪庆藏族自治州
     云南省	大理白族自治州
     云南省	楚雄彝族自治州
     云南省	红河哈尼族彝族自治州
     云南省	文山壮族苗族自治州
     云南省	西双版纳傣族自治州
     */
    AKCityTypeAutonomousPrefecture,//自治州
    
    /**
     兴安盟
     锡林郭勒盟
     阿拉善盟
     */
    AKCityTypeLeague,//盟
};

NS_ASSUME_NONNULL_BEGIN

@interface AKCity : NSObject

@property (nonatomic, copy) NSString *cityID;/**<省ID*/
@property (nonatomic, copy) NSString *cName;/**<中文名*/
@property (nonatomic, copy) NSString *spell;/**<拼音*/
@property (nonatomic, copy) NSString *eName;/**<英文名*/

@property (nonatomic, assign ) AKCityType type;/**<类型*/

@end

NS_ASSUME_NONNULL_END
