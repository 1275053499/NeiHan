//
//  NHBaseImageView.h
//  NeiHan
//
//  Created by Charles on 16/9/8.
//  Copyright © 2016年 Charles. All rights reserved.
//

#import "YYAnimatedImageView.h"

@interface NHBaseImageView : YYAnimatedImageView

- (void)setImageWithUrl:(NSString *)url;

- (void)setImageWithURL:(NSURL *)URL;

- (void)setImageWithUrl:(NSString *)url
            placeHolder:(UIImage *)image;

- (void)setImageWithURL:(NSURL *)URL
            placeHolder:(UIImage *)image;

- (void)setImageWithUrl:(NSString *)url
            placeHolder:(UIImage *)image
           finishHandle:(void(^)(BOOL finished, UIImage *image))finishHandle;

- (void)setImageWithURL:(NSURL *)URL
            placeHolder:(UIImage *)image
           finishHandle:(void(^)(BOOL finished, UIImage *image))finishHandle;


- (void)setImageWithUrl:(NSString *)url
            placeHolder:(UIImage *)image
         progressHandle:(void(^)(CGFloat progress))progressHandle
           finishHandle:(void(^)(BOOL finished, UIImage *image))finishHandle;

- (void)setImageWithURL:(NSURL *)URL placeHolder:(UIImage *)image
         progressHandle:(void(^)(CGFloat progress))progressHandle
           finishHandle:(void(^)(BOOL finished, UIImage *image))finishHandle;
@end

