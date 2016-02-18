//
//  UIButton+IBnspectable.h
//  Category-Xib
//
//  Created by 李攀祥 on 16/2/18.
//  Copyright © 2016年 李攀祥. All rights reserved.
//

#import <UIKit/UIKit.h>
IB_DESIGNABLE
@interface UIButton (IBnspectable)
/*!
 * 设置 按钮 title的Hex Color
 * 如果不设置 系统会调用系统自在的UIButton:textColor
 * 如果设置了 Hex Color 则系统自在的UIButton:textColor 将失效
 */
@property (assign,nonatomic) IBInspectable NSString *titleHexColor;
@end
