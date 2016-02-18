#####不需要一句代码，给UI控件设置圆角和阴影及1px的兼容

* 在Xib中 系统自带的UI控件中 添加一些 额外的属性
* eg：
![](http://upload-images.jianshu.io/upload_images/1418424-870c125110809f27.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
* 效果
![](http://upload-images.jianshu.io/upload_images/1418424-ffc98941d956067d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



####示例代码：
>特别注意：
如果想实时监听MBIBnspectable的改变的话，需要继承一个空的基类，或者自定义的类。
  如果需要的话请继承于PXBaseView.h



* UIView的xib扩展
* .h文件

```
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
```

* .m文件的实现

```
@implementation UIView (IBnspectable)
- (void)setCornerRadius:(NSInteger)cornerRadius{
    self.layer.cornerRadius = cornerRadius;
    self.layer.masksToBounds = cornerRadius > 0;
}

- (NSInteger)cornerRadius{
    return self.layer.cornerRadius;
}

- (void)setBorderWidth:(NSInteger)borderWidth{
    self.layer.borderWidth = borderWidth;
}

- (NSInteger)borderWidth{
    return self.layer.borderWidth;
}

- (void)setBorderColor:(UIColor *)borderColor{
    self.layer.borderColor = borderColor.CGColor;
}

- (UIColor *)borderColor{
    return [UIColor colorWithCGColor:self.layer.borderColor];
}

- (void)setBorderHexRgb:(NSString *)borderHexRgb{
    NSScanner *scanner = [NSScanner scannerWithString:borderHexRgb];
    unsigned hexNum;
    //这里是将16进制转化为10进制
    if (![scanner scanHexInt:&hexNum])
        return;
    self.layer.borderColor = [self colorWithRGBHex:hexNum].CGColor;
}

-(NSString *)borderHexRgb{
    return @"0xffffff";
}

- (void)setMasksToBounds:(BOOL)bounds{
    self.layer.masksToBounds = bounds;
}

- (BOOL)masksToBounds{
    return self.layer.masksToBounds;
}

#pragma mark - hexRgbColor
- (void)setHexRgbColor:(NSString *)hexRgbColor{
    NSScanner *scanner = [NSScanner scannerWithString:hexRgbColor];
    unsigned hexNum;
    if (![scanner scanHexInt:&hexNum]) return;
    self.backgroundColor = [self colorWithRGBHex:hexNum];
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


- (NSString *)hexRgbColor{
    return @"0xffffff";
}

#pragma mark - setOnePx
- (void)setOnePx:(BOOL)onePx{
    if (onePx) {
        CGRect rect = self.frame;
        rect.size.height = 5/ [UIScreen mainScreen].scale;
        self.frame = rect;
    }
}

- (BOOL)onePx{
    return self.onePx;
}
@end

```



  

s