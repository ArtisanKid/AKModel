//
//  AKVillage.h
//  Pods
//
//  Created by 李翔宇 on 2017/7/31.
//
//

//村级行政单位

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AKVillage : NSObject

@property (nonatomic, copy) NSString *villageID;/**<村ID*/
@property (nonatomic, copy) NSString *cName;/**<中文名*/
@property (nonatomic, copy) NSString *spell;/**<拼音*/
@property (nonatomic, copy) NSString *eName;/**<英文名*/

@end

NS_ASSUME_NONNULL_END
