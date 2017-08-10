//
//  AKPlace.h
//  Pods
//
//  Created by 李翔宇 on 2017/8/1.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>

#import "AKCountry.h"
#import "AKProvince.h"
#import "AKCity.h"
#import "AKCounty.h"
#import "AKTownship.h"
#import "AKVillage.h"
#import "AKNeighborhood.h"
#import "AKPlacemark.h"

NS_ASSUME_NONNULL_BEGIN

@interface AKPlace : NSObject

@property (nonatomic, assign) CLLocationCoordinate2D locationCoordinate;/**<定位坐标*/

@property (nonatomic, strong) AKCountry *country;/**<国家*/

/**
 省级行政区
 */
@property (nonatomic, strong) AKProvince *province;/**<省*/

/**
 地级行政区
 */
@property (nonatomic, strong) AKCity *city;/**<地级市*/

/**
 县级行政区
 */
@property (nonatomic, strong) AKCounty *county;/**<县*/

/**
 乡级行政区
 */
@property (nonatomic, strong) AKTownship *township;/**<乡*/

/**
 村级行政区
 */
@property (nonatomic, strong) AKVillage *village;/**<村*/

/**
 居民区
 */
@property (nonatomic, strong) AKNeighborhood *neighborhood;

/**
 标记
 */
@property (nonatomic, strong) AKPlacemark *placemark;

@end

NS_ASSUME_NONNULL_END
