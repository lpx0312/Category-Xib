//
//  UILabel+IBnspectable.h
//  Category-Xib
//
//  Created by 李攀祥 on 16/2/18.
//  Copyright © 2016年 李攀祥. All rights reserved.
//

#import <UIKit/UIKit.h>
IB_DESIGNABLE
@interface UILabel (IBnspectable)
/*!
 * 设置text的 hex color
 */
@property (assign,nonatomic) IBInspectable NSString *textHexColor;
@end
