//
//  NHBaseModel.m
//  NeiHan
//
//  Created by Charles on 16/8/30.
//  Copyright © 2016年 Charles. All rights reserved.
//

#import "NHBaseModel.h"
#import "MJExtension.h"

@implementation NHBaseModel

MJCodingImplementation;

+ (NSDictionary *)replacedKeyFromPropertyName {
    return @{
             @"ID":@"id",
             @"desc":@"description",
             @"responseData" : @"data"
             };
}

+ (NSMutableArray *)modelArrayWithDictArray:(NSArray *)response {
    if ([response isKindOfClass:[NSArray class]]) {
        NSMutableArray *array = [self mj_objectArrayWithKeyValuesArray:response];
        return array;
    }
    return [NSMutableArray new];
}

+ (id)modelWithDictionary:(NSDictionary *)dictionary {
    if ([dictionary isKindOfClass:[NSDictionary class]]) {
        return [self mj_objectWithKeyValues:dictionary];
    }
    return [[self alloc] init];
}
 
@end
