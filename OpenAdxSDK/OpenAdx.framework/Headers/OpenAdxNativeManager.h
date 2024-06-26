//
//  OpenAdxNative.h
//  CloooudAPIAd
//
//  Created by fyl on 2024/4/28.
//

#import "OpenAdxBaseAd.h"
#import "OpenAdxError.h"
#import "OpenAdxNativeView.h"
#import "OpenAdxNativeAd.h"

@protocol OpenAdxNativeManagerDelegate <NSObject>

@optional

/// 广告加载失败
/// - Parameter error: error 信息
- (void)onAdLoadError:(OpenAdxError *_Nonnull)error;

/// 广告加载成功
/// - Parameter adDataArr: nativeAd 对象数组
- (void)onAdLoaded:(NSArray <OpenAdxNativeAd *>*_Nonnull)adDataArr;

@end

NS_ASSUME_NONNULL_BEGIN

@interface OpenAdxNativeManager : OpenAdxBaseAd

/// 代理
@property(weak,nonatomic)id <OpenAdxNativeManagerDelegate>delegate;

/// 是否可用
@property(assign,nonatomic)BOOL isValid;

/// 广告位 ID
@property(copy,nonatomic,readonly)NSString *slotID;

///  初始化广告对象
/// - Parameters:
///   - slotID: 广告位 ID
///   - rootViewController: 用于跳转的控制器
- (instancetype)initWithSlotID:(NSString *)slotID rootViewController:(UIViewController *)rootViewController;

/// 加载广告
/// - Parameter count: 数量 1-3
- (void)loadAdWithCount:(NSInteger)count;


@end

NS_ASSUME_NONNULL_END
