//
//  OpenAdxBaseAd.h
//  CloooudAPIAd
//
//  Created by fyl on 2024/4/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OpenAdxError.h"
#import "OpenAdxEventsRepoter.h"

@class OpenAdxResultData;

NS_ASSUME_NONNULL_BEGIN

@interface OpenAdxBaseAd : NSObject


/// 超时时间 单位 :s, 默认: 3s
@property(assign,nonatomic)NSTimeInterval timeoutInterval;

/// 价格,单位分
@property(assign,nonatomic)NSInteger ecpm;

/// 广告 size
@property(assign,nonatomic)CGSize adSize;

/// 事件上报
@property(strong,nonatomic)OpenAdxEventsRepoter *repoter;

/// 上报事件
/// - Parameters:
///   - eventsType: 事件类型
///   - adData: 广告数据
- (void)reportEvents:(OpenAdxEventsType)eventsType adData:(OpenAdxResultData *)adData;

/// 销毁广告
- (void)destoryAd;

@end

NS_ASSUME_NONNULL_END
