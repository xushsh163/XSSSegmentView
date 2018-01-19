//
//  SegmentViewControlDemo.h
//  SegmentControlDemo
//
//  Created by xushsh on 16/1/25.
//  Copyright © 2016年 xushsh. All rights reserved.
//

#import <UIKit/UIKit.h>

#ifdef DEBUG
#define kDLOG(FORMAT, ...) fprintf(stderr,"%s: %d\t  %s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String])
#define NSLog(...)  NSLog(__VA_ARGS__)
#else
#define kDLOG(...)
#define NSLog(...)
#endif
/**
 *  定义的协议
 */
@protocol SegmentViewControlDelegate< NSObject>
/**
 *  创建segment的类需要实现的协议方法，可选
 *
 *  @param selection 选中的下标
 */
@optional
-(void)didSelectSegmentAtIndex:(NSInteger)selectedIndex;
@end

@interface SegmentView : UIView
/**
 *  自定义下标，需要在 addItems...方法后设置，否则程序会崩溃
 */
@property (nonatomic, assign) NSInteger  selectedIndex;
/**
 *  当前类的代理对象，把要实现选择segment的类的对象设置成代理
 */
@property (nonatomic, weak) id <SegmentViewControlDelegate> delegate;
/**
 *  标题  ，目前仅支持字符串，暂时未考虑图片
 */
@property (nonatomic, strong) NSMutableArray *itemArray;
/**
 *  一一对应于点击每个item时显示的view
 */
@property (nonatomic, strong) NSMutableArray *segSubviews;
/**
 *  子控制器  segSubviews与subControllers只能设置一个,或者均不设置
 */
@property (nonatomic, strong) NSMutableArray *segSubControllers;
/**
 *  segment的背景色，不设置的话会采用默认值
 */
@property (strong, nonatomic) UIColor *segmentBackgroundColor;
/**
 *  选中时的背景色，不设置的话会采用默认值
 */
@property (strong, nonatomic) UIColor *selectedBackgroundColor;
/**
 *  segment的字体颜色，不设置的话采用默认值
 */
@property (strong, nonatomic) UIColor *titleColor;
/**
 *  segment选中时的字体颜色，不设置的话采用默认值
 */
@property (strong, nonatomic) UIColor *selectColor;
/**
 *  segment标题的字体，不设置的采用默认值
 */
@property (strong, nonatomic) UIFont  *titleFont;
/**
 *  segment的下划线的颜色，不设置的采用默认的红色
 */
@property (strong, nonatomic) UIColor *lineColor;
/**
 *  segment下划线动画的时间，不设置的话默认0.5s
 */
@property (assign, nonatomic) CGFloat duration;
/**
 *  创建segment，每次均会返回一个新的SegmentView对象，以便于实现segment的嵌套使用
 *
 *  @return SegmentView对象
 */
+(instancetype )initSegment;
/**
 *  要添加的items
 *
 *  @param items 标题数组
 *  @param frame segment的frame
 *  @param view  segment要添加的view
 */
-(void)addItems:(NSArray *)items frame:(CGRect )frame inView:(UIView *)view;
-(void)addItems:(NSArray *)items;
-(void)replaceItems:(NSArray *)items;
-(void)selectIndex:(NSInteger)index;
/**
 *  选中时有图片的接口
 *
 *  @param frame         segment的frame
 *  @param titles        标题数组
 *  @param selectedImage 选中的图片
 *  @param view          要添加到的view
 */
-(void)addItemsWithFrame:(CGRect)frame titles:(NSArray *)titles selectedImage:(NSString *)selectedImage inView:(UIView *)view;
@end

