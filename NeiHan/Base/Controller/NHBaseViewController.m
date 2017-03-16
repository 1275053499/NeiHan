//
//  NHBaseViewController.m
//  NeiHan
//
//  Created by Charles on 16/8/30.
//  Copyright © 2016年 Charles. All rights reserved.
//

#import "NHBaseViewController.h"
#import "NHCustomNoNetworkEmptyView.h"
#import "NSNotificationCenter+Addition.h"
#import "NHCustomLoadingAnimationView.h"
#import "NHLocationManager.h"
#import "AFNetworkReachabilityManager.h"
#import "YYWebImageManager.h"
#import "YYDiskCache.h"
#import "YYMemoryCache.h"

@interface NHBaseViewController ()

@property (nonatomic, weak) NHCustomNoNetworkEmptyView *noNetworkEmptyView;

@property (nonatomic, weak) NHCustomLoadingAnimationView *animationView;

@end

@implementation NHBaseViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [UIView setAnimationsEnabled:YES];
    [self.navigationController setNavigationBarHidden:NO animated:YES];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [UIView setAnimationsEnabled:YES];
    self.automaticallyAdjustsScrollViewInsets = NO;
    self.edgesForExtendedLayout = UIRectEdgeAll;
    self.view.backgroundColor = [UIColor colorWithRed:0.94f green:0.94f blue:0.94f alpha:1.00f];
}

- (void)requestSuccessNotification {
    [self hideLoadingAnimation];
}

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)pop {
    if (!self.navigationController) return;
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)popToRootVc {
    if (!self.navigationController) return;
    [self.navigationController popToRootViewControllerAnimated:YES];
}

- (void)popToVc:(UIViewController *)vc {
    if (![vc isKindOfClass:[UIViewController class]]) return;
    if (!self.navigationController) return;
    [self.navigationController popToViewController:vc animated:YES];
}

- (void)dismiss {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)dismissWithCompletion:(void(^)())completion {
    [self dismissViewControllerAnimated:YES completion:completion];
}

- (void)presentVc:(UIViewController *)vc {
    if (![vc isKindOfClass:[UIViewController class]]) return;
    [self presentVc:vc completion:nil];
}

- (void)presentVc:(UIViewController *)vc completion:(void (^)(void))completion {
    if (![vc isKindOfClass:[UIViewController class]]) return;
    [self presentViewController:vc animated:YES completion:completion];
}

- (void)pushVc:(UIViewController *)vc {
    if (![vc isKindOfClass:[UIViewController class]]) return;
    if (!self.navigationController) return;
    if (vc.hidesBottomBarWhenPushed == NO) {
        vc.hidesBottomBarWhenPushed = YES;
    }
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)removeChildVc:(UIViewController *)childVc {
    if (![childVc isKindOfClass:[UIViewController class]]) return;
    [childVc.view removeFromSuperview];
    [childVc willMoveToParentViewController:nil];
    [childVc removeFromParentViewController];
}

- (void)addChildVc:(UIViewController *)childVc {
    if (![childVc isKindOfClass:[UIViewController class]]) return;
    [childVc willMoveToParentViewController:self];
    [self addChildViewController:childVc];
    [self.view addSubview:childVc.view];
    childVc.view.frame = self.view.bounds;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}

- (NHCustomNoNetworkEmptyView *)noNetworkEmptyView {
    if (!_noNetworkEmptyView) {
        NHCustomNoNetworkEmptyView *empty = [[NHCustomNoNetworkEmptyView alloc] init];
        [self.view addSubview:empty];
        _noNetworkEmptyView = empty;
        WeakSelf(weakSelf);
        [empty mas_makeConstraints:^(MASConstraintMaker *make) {
            make.edges.equalTo(weakSelf.view);
        }];
        empty.customNoNetworkEmptyViewDidClickRetryHandle = ^(NHCustomNoNetworkEmptyView *emptyView) {
        };
    }
    return _noNetworkEmptyView;
}

- (void)loadData {
    
}

- (void)showLoadingAnimation {
    NHCustomLoadingAnimationView *animation = [[NHCustomLoadingAnimationView alloc] init];
    [animation showInView:self.view];
    _animationView = animation;
    [self.view bringSubviewToFront:animation];
}

- (void)hideLoadingAnimation {
    [_animationView dismiss];
    _animationView = nil;
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    [self.view bringSubviewToFront:self.animationView];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
    [[SDImageCache sharedImageCache] setValue:nil forKey:@"memCache"];
    [[[YYWebImageManager sharedManager] cache].diskCache removeAllObjects];
    [[[YYWebImageManager sharedManager] cache].memoryCache removeAllObjects];
}

@end
