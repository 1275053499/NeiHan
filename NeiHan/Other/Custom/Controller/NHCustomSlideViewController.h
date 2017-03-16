//
//  NHCustomSlideViewController.h
//  NeiHan
//
//  Created by Charles on 16/8/31.
//  Copyright © 2016年 Charles. All rights reserved.
//

#import <UIKit/UIKit.h>

@class NHCustomSlideViewController;

@protocol NHCustomSlideViewControllerDelegate <NSObject>

@optional
- (void)customSlideViewController:(NHCustomSlideViewController *)slideViewController slideOffset:(CGPoint)slideOffset;

- (void)customSlideViewController:(NHCustomSlideViewController *)slideViewController slideIndex:(NSInteger)slideIndex;

@end

@protocol NHCustomSlideViewControllerDataSource <NSObject>

- (UIViewController *)slideViewController:(NHCustomSlideViewController *)slideViewController viewControllerAtIndex:(NSInteger)index;

- (NSInteger)numberOfChildViewControllersInSlideViewController:(NHCustomSlideViewController *)slideViewController;

@end

@interface NHCustomSlideViewController : UIViewController

@property (nonatomic, weak) id <NHCustomSlideViewControllerDelegate> delgate;

@property (nonatomic, weak) id <NHCustomSlideViewControllerDataSource> dataSource;

@property (nonatomic, assign) NSInteger seletedIndex;

- (void)reloadData;

@end
