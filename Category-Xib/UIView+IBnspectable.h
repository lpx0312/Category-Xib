//
//  UIView+IBnspectable.h
//  Category-Xib
//
//  Created by 李攀祥 on 16/2/18.
//  Copyright © 2016年 李攀祥. All rights reserved.
//

#import <UIKit/UIKit.h>
IB_DESIGNABLE
/** View的XIB可视化扩展类> */
@interface UIView (IBnspectable)
/*!
 * 给UIView 设置圆角
 */
@property (assign,nonatomic) IBInspectable NSInteger cornerRadius;
@property (assign,nonatomic) IBInspectable BOOL  masksToBounds;

/*!
 * 设置 view的 边框颜色(选择器和Hex颜色) 
 * 以及 边框的宽度
 */
@property (assign,nonatomic) IBInspectable NSInteger borderWidth;
@property (strong,nonatomic) IBInspectable NSString  *borderHexRgb;
@property (strong,nonatomic) IBInspectable UIColor   *borderColor;


/*!
 * 设置view的背景Hex颜色 (选择器颜色 是系统自带的不需要写)
 */
@property (assign,nonatomic) IBInspectable NSString  *hexRgbColor;
//TODO: 特别注意
/*!
 * 这个属性可以开启 Retina屏对 1px的支持
 * Retain屏的分辨率 [UIScreen mainScreen].scale分辨率是 >=2
 * 
 */
@property (assign,nonatomic) IBInspectable BOOL      onePx;

@end
