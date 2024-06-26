//
//  OpenAdxBanner.h
//  CloooudAPIAd
//
//  Created by fyl on 2024/4/28.
//

#import "OpenAdxBaseAd.h"
#import "OpenAdxError.h"

@protocol OpenAdxBannerDelegate <NSObject>

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

@interface OpenAdxBanner : OpenAdxBaseAd

/// 广告视图
@property(strong,nonatomic,readonly)UIView *adView;

/// 代理
@property(weak,nonatomic)id <OpenAdxBannerDelegate>delegate;

/// 是否可用
@property(assign,nonatomic)BOOL isValid;

/// 广告位ID
@property(copy,nonatomic,readonly)NSString *slotID;

///  初始化广告对象
/// - Parameters:
///   - slotID: 广告位 ID
///   - rootViewController: 用于跳转的控制器
///   - adSize: 期望的广告视图 size
- (instancetype)initWithSlotID:(NSString *)slotID rootViewController:(UIViewController *)rootViewController adSize:(CGSize)adSize;

/// 加载广告
- (void)loadAdData;

@end

NS_ASSUME_NONNULL_END
