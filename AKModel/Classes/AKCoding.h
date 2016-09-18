//
//  AKCoding.h
//  Pods
//
//  Created by 李翔宇 on 16/2/16.
//
//

#ifndef AKCoding_h
#define AKCoding_h
 
#import <YYModel/YYModel.h>

//ARC下标准的NSCoding实现（借助YYModel）
//__Class__ 类名
//__Init__  单例方法名
#define AKCoding \
\
    - (id)initWithCoder:(NSCoder *)decoder {\
        if (self = [super init]) {\
            [self yy_modelInitWithCoder:decoder];\
        }\
        return self;\
    }\
\
    - (void)encodeWithCoder:(NSCoder *)encoder {\
        [self yy_modelEncodeWithCoder:encoder];\
    }

#endif /* AKCoding_h */
