//
//  NHBaseRequest.h
//  NeiHan
//
//  Created by Charles on 16/8/30.
//  Copyright © 2016年 Charles. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef void(^NHAPIDicCompletion)(id response, BOOL success, NSString *message);

@interface NHBaseRequest : NSObject

@property (nonatomic, copy) NSString *nh_url;

@property (nonatomic, assign) BOOL nh_isPost;

@property (nonatomic, strong) NSArray <UIImage *>*nh_imageArray;

+ (instancetype)nh_request;

+ (instancetype)nh_requestWithUrl:(NSString *)nh_url;

+ (instancetype)nh_requestWithUrl:(NSString *)nh_url isPost:(BOOL)nh_isPost;

- (void)nh_sendRequestWithCompletion:(NHAPIDicCompletion)completion;

@end
