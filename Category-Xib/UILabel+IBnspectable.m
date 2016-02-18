//
//  UILabel+IBnspectable.m
//  Category-Xib
//
//  Created by 李攀祥 on 16/2/18.
//  Copyright © 2016年 李攀祥. All rights reserved.
//

#import "UILabel+IBnspectable.h"

@implementation UILabel (IBnspectable)
#pragma mark - hexRgbColor
- (void)setTextHexColor:(NSString *)textHexColor{
    NSScanner *scanner = [NSScanner scannerWithString:textHexColor];
    unsigned hexNum;
    if (![scanner scanHexInt:&hexNum]) return;
    self.textColor = [self colorWithRGBHex:hexNum];
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


- (NSString *)textHexColor{
    return @"0xffffff";
}

@end
