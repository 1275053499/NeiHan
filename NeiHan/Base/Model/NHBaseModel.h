//
//  NHBaseModel.h
//  NeiHan
//
//  Created by Charles on 16/8/30.
//  Copyright © 2016年 Charles. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NHBaseModel : NSObject 

/**
 *  字典数组转模型数组
 */
+ (NSMutableArray *)modelArrayWithDictArray:(NSArray *)response;

/**
 *  字典转模型
 */
+ (instancetype)modelWithDictionary:(NSDictionary *)dictionary;

@end
