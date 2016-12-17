//
//  AKModelMacro.h
//  Pods
//
//  Created by 李翔宇 on 2016/12/17.
//
//

#ifndef AKModelMacro_h
#define AKModelMacro_h

static BOOL AKModelLogStateOpen;

#if DEBUG
#define AKModelLog(INFO, ...) AKModelLogStateOpen ? NSLog((@"\n[Time:%@]\n[File:%s]\n[Line:%d]\n[Function:%s]\n" INFO @"\n\n"), NSDate.date, __FILE__, __LINE__, __PRETTY_FUNCTION__, ## __VA_ARGS__) : nil;
#else
#define AKModelLog(INFO, ...)
#endif

#endif /* AKModelMacro_h */
