//
//  NHBaseTableHeaderFooterView.h
//  NeiHan
//
//  Created by Charles on 16/8/31.
//  Copyright © 2016年 Charles. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NHBaseTableHeaderFooterView : UITableViewHeaderFooterView

+ (instancetype)headerFooterViewWithTableView:(UITableView *)tableView;

+ (instancetype)nibHeaderFooterViewWithTableView:(UITableView *)tableView;
 
@end
