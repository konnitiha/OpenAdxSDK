//
//  OpenAdxRewardVideo.h
//  OpenAdx
//
//  Created by fyl on 2024/5/8.
//

#import "OpenAdxBaseAd.h"

@protocol OpenAdxRewardVideoDelegate <NSObject>

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

/// 视频加载成功
- (void)onAdDidDownloadVideo;

/// 达到激励条件
- (void)onAdDidRewardSuccess;

@end

NS_ASSUME_NONNULL_BEGIN

@interface OpenAdxRewardVideo : OpenAdxBaseAd

/// 代理
@property(weak,nonatomic)id <OpenAdxRewardVideoDelegate>delegate;

/// 是否可用
@property(assign,nonatomic)BOOL isValid;

/// 广告位 ID
@property(copy,nonatomic,readonly)NSString *slotID;

///  创建广告对象
/// - Parameter slotID: 广告位 ID
- (instancetype)initWithSlotID:(NSString *)slotID;

/// 加载广告
- (void)loadAdData;

/// 展示广告
/// - Parameter viewController: 用于跳转的控制器
- (void)showRewardVideoInRootViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
