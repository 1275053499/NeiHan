//
//  NHBaseTableViewCell.h
//  NeiHan
//
//  Created by Charles on 16/8/30.
//  Copyright © 2016年 Charles. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NHBaseTableViewCell : UITableViewCell

+ (instancetype)cellWithTableView:(UITableView *)tableView;

+ (instancetype)nibCellWithTableView:(UITableView *)tableView;

@end
