//
//  AKNeighborhood.h
//  Pods
//
//  Created by 李翔宇 on 2017/8/1.
//
//

//居民区

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AKNeighborhood : NSObject

@property (nonatomic, copy) NSString *villageID;/**<村ID*/
@property (nonatomic, copy) NSString *cName;/**<中文名*/
@property (nonatomic, copy) NSString *spell;/**<拼音*/
@property (nonatomic, copy) NSString *eName;/**<英文名*/

@end

NS_ASSUME_NONNULL_END
