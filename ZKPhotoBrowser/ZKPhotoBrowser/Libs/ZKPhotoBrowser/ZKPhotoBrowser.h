//
//  ZKPhotoBrowser.h
//
//  Created by ZK on 16/7/19.
//  Copyright © 2016年 ZK. All rights reserved.
//

#import <UIKit/UIKit.h>
@class ZKPhotoBrowser;

@protocol ZKPhotoBrowserDelegate <NSObject>
@optional
/** 切换到某一页图片 */
- (void)photoBrowser:(ZKPhotoBrowser *)photoBrowser didChangedToPageAtIndex:(NSUInteger)index;
@end

@interface ZKPhotoBrowser : UIViewController <UIScrollViewDelegate>

@property (nonatomic, weak) id<ZKPhotoBrowserDelegate> delegate;

/*!
 * imageUrls: 大图图片链接
 * index: 当前点击图片的下标
 * superView: 盛放当前图片 imageView 视图的父视图
 *
 */
+ (instancetype)showWithImageUrls:(NSArray<NSString *> *)imageUrls
                currentPhotoIndex:(NSUInteger)index
                  sourceSuperView:(UIView *)superView;

@end

#define MCDisableAutoAdjustScrollViewInsets(scrollView, vc)\
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"") \
if (@available(iOS 11.0,*))  {\
scrollView.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;\
} else {\
vc.automaticallyAdjustsScrollViewInsets = NO;\
}\
_Pragma("clang diagnostic pop")\
} while (0);

#define MCDisableTableViewEstimatedHeight(tableView) \
tableView.estimatedRowHeight = tableView.estimatedSectionFooterHeight = tableView.estimatedSectionHeaderHeight = 0;
