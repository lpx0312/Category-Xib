//
//  UIButton+IBnspectable.m
//  Category-Xib
//
//  Created by 李攀祥 on 16/2/18.
//  Copyright © 2016年 李攀祥. All rights reserved.
//

#import "UIButton+IBnspectable.h"

@implementation UIButton (IBnspectable)

#pragma mark - hexRgbColor


- (NSString *)titleHexColor{
    //这个默认的设置 可有可无 因为默认会调用系统的 UIButton :text Color
    return @"0xffffff";
}

- (void)setTitleHexColor:(NSString *)titleHexColor{
    NSScanner *scanner = [NSScanner scannerWithString:titleHexColor];
    unsigned hexNum;
    if (![scanner scanHexInt:&hexNum]) return;
    [self setTitleColor:[self colorWithRGBHex:hexNum] forState:UIControlStateNormal];
}

- (UIColor *)colorWithRGBHex:(UInt32)hex {
    int r = (hex >> 16) & 0xFF;
    int g = (hex >> 8) & 0xFF;
    int b = (hex) & 0xFF;
    return [UIColor colorWithRed:r / 255.0f
                           green:g / 255.0f
                            blue:b / 255.0f
                           alpha:1.0f];
}





@end
