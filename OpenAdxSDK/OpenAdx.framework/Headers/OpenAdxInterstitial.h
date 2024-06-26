//
//  OpenAdxInterstitial.h
//  CloooudAPIAd
//
//  Created by fyl on 2024/4/28.
//

#import "OpenAdxBaseAd.h"
#import "OpenAdxError.h"

@protocol OpenAdxInterstitialDelegate <NSObject>

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

@interface OpenAdxInterstitial : OpenAdxBaseAd

/// 代理
@property(weak,nonatomic)id <OpenAdxInterstitialDelegate>delegate;

/// 是否可用
@property(assign,nonatomic)BOOL isValid;

/// 广告位ID
@property(copy,nonatomic,readonly)NSString *slotID;

/// 初始化广告对象
/// - Parameters:
///   - slotID: 广告位 ID
///   - sizeForInterstitial: 期望的广告尺寸
- (instancetype)initWithSlotID:(NSString *)slotID sizeForInterstitial:(CGSize)sizeForInterstitial;

/// 加载广告
- (void)loadAdData;

/// 展示广告
/// - Parameter viewController: 用于跳转的控制器
- (void)showInterstitialAdInRootViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END

