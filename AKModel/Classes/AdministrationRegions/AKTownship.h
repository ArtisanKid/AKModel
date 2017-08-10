//
//  AKTownship.h
//  Pods
//
//  Created by 李翔宇 on 2017/8/1.
//
//

//乡

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AKTownshipType) {
    AKTownshipTypeDefault,//乡
    
    AKTownshipTypeTown,//镇
    
    AKTownshipTypeNationalityTownship,//民族乡
    
    AKTownshipTypeSum,//苏木
    
    AKTownshipTypeNationalitySum,//民族苏木
    
    AKTownshipTypeSubdistrictOffice,//街道办事处
};

NS_ASSUME_NONNULL_BEGIN

@interface AKTownship : NSObject

@property (nonatomic, copy) NSString *townshipID;/**<省ID*/
@property (nonatomic, copy) NSString *cName;/**<中文名*/
@property (nonatomic, copy) NSString *spell;/**<拼音*/
@property (nonatomic, copy) NSString *eName;/**<英文名*/

@property (nonatomic, assign ) AKTownshipType type;/**<类型*/

@end

NS_ASSUME_NONNULL_END
