//
//  NHNeiHanUserInfoModel.h
//  NeiHan
//
//  Created by Charles on 16/9/2.
//  Copyright © 2016年 Charles. All rights reserved.
//

#import "NHBaseModel.h"

@interface NHNeiHanUserInfoModel : NHBaseModel

@property (nonatomic, assign) NSInteger user_id;

@property (nonatomic, assign) NSInteger create_time;

@property (nonatomic, assign) NSInteger repin_count;

@property (nonatomic, assign) NSInteger new_followers;

@property (nonatomic, assign) NSInteger notification_count;

@property (nonatomic, assign) NSInteger point;

@property (nonatomic, assign) NSInteger ugc_count;

@property (nonatomic, assign) NSInteger subscribe_count;

@property (nonatomic, assign) NSInteger followers;

@property (nonatomic, assign) NSInteger gender;

@property (nonatomic, assign) NSInteger ID;

@property (nonatomic, assign) NSInteger followings;

@property (nonatomic, assign) NSInteger comment_count;

@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *avatar_url;

@property (nonatomic, copy) NSString *large_avatar_url;

@property (nonatomic, copy) NSString *screen_name;

@property (nonatomic, copy) NSString *desc;

@property (nonatomic, assign) BOOL is_following;

@property (nonatomic, assign) BOOL user_verified;

@end
