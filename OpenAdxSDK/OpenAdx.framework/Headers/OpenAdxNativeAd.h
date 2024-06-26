//
//  OpenAdxNativeAd.h
//  OpenAdx
//
//  Created by fyl on 2024/5/30.
//

#import "OpenAdxBaseAd.h"
#import <UIKit/UIKit.h>
#import "OpenAdxMaterialMeta.h"

@protocol OpenAdxNativeAdDelegate <NSObject>

@optional

/// 广告点击
- (void)onAdClick;

/// 广告曝光
- (void)onAdExposure;

@end

NS_ASSUME_NONNULL_BEGIN

@interface OpenAdxNativeAd : OpenAdxBaseAd


/// 广告数据对象
@property (nonatomic, strong, readonly, nullable) OpenAdxMaterialMeta *data;

/// 代理
@property (nonatomic, weak, readwrite, nullable) id<OpenAdxNativeAdDelegate> delegate;

/// 用于跳转的控制器
@property (nonatomic, weak, readwrite) UIViewController *rootViewController;

/// 注册容器和点击视图
/// - Parameters:
///   - containerView: 容器
///   - clickableViews: 点击视图数组
- (void)registerContainer:(__kindof UIView *)containerView withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews;


@end

NS_ASSUME_NONNULL_END
