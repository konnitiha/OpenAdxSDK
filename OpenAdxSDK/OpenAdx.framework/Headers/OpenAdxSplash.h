//
//  OpenAdxSplash.h
//  CloooudAPIAd
//
//  Created by fyl on 2024/4/24.
//
#import <UIKit/UIKit.h>
#import "OpenAdxBaseAd.h"
#import "OpenAdxError.h"




@protocol OpenAdxSplashDelegate <NSObject>

@optional

/// 广告关闭
- (void)onAdDismiss;

/// 广告加载失败
/// - Parameter error: 失败信息
- (void)onAdLoadError:(OpenAdxError *_Nonnull)error;

/// 广告点击
- (void)onAdClick;

/// 广告曝光
- (void)onAdExposure;

/// 广告加载成功
- (void)onAdLoaded;

@end

NS_ASSUME_NONNULL_BEGIN

@interface OpenAdxSplash : OpenAdxBaseAd

/// 代理
@property(weak,nonatomic)id <OpenAdxSplashDelegate>delegate;

/// 倒计时秒数:默认 5s
@property(assign,nonatomic)int countDownTime;

/// 是否可用
@property(assign,nonatomic)BOOL isValid;

/// 广告位 ID
@property(copy,nonatomic,readonly)NSString *slotID;


/// 底部视图,最大高度为屏幕高的 0.25
@property(strong,nonatomic)UIView *bottomView;

///  初始化广告对象
/// - Parameter slotID: 广告位 ID
- (instancetype)initWithSlotID:(NSString *)slotID;

/// 加载广告
- (void)loadAdData;

/// 展示广告
/// - Parameter viewController: 用于跳转的控制器
- (void)showSplashAdInRootViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
