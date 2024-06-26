//
//  OpenAdxResultData.h
//  CloooudAPIAd
//
//  Created by fyl on 2024/4/23.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CloooudBidResponseActionType) {
    CloooudBidResponseActionType_Net = 0,
    CloooudBidResponseActionType_DownLoad,
};

@class BidResponse;

NS_ASSUME_NONNULL_BEGIN

@interface OpenAdxResultData : NSObject

- (instancetype)initWithBidResponse:(BidResponse *)bidResponse;

/// ADX请求时⽣成的id保持⼀致
@property(strong,nonatomic)NSString *idd;

/// 竞价响应id
@property(strong,nonatomic)NSString *bidId;


/// 曝光Id
@property(strong,nonatomic)NSString *impId;

/// 出价，单位⼈⺠币分
@property(assign,nonatomic)NSInteger price;

/// winnotice地址
@property(strong,nonatomic)NSArray<NSString *> *noticeURLArray;

/// 展现监测地址列表。若为视频⼴告，则展现监测地址为“视频完成播放”的监测地址
@property(strong,nonatomic)NSArray<NSString *> *impArray;

/// 点击监测地址列表
@property(strong,nonatomic)NSArray<NSString *> *clkArray;

/// 0- ⽹⻚ 1- 下载
@property(assign,nonatomic)CloooudBidResponseActionType action;

/// 点击落地⻚，如果是app下载，则为app下载地址。点击地址须优先使⽤deeplink，landing次之
@property(strong,nonatomic)NSString *landing;

/// ⼴告来源标识⽂字
@property(strong,nonatomic)NSString *source;

/// ⼴告来源标识的logo图⽚url
@property(strong,nonatomic)NSString *logo;

/// dpLink地址,如果媒体⽀持deeplink。点击地址须优先使⽤dpLink，landing次之
@property(strong,nonatomic)NSString *dpLink;

/// Ios 会存在 dpLink地址,如果媒体⽀持deepUlink。点击地址须优先使⽤dpLink，landing次之
@property(strong,nonatomic)NSString *deepUlink;

/// dp唤起成功监测
@property(strong,nonatomic)NSArray<NSString *> *dpSuccessArray;

/// dp唤起失败监测
@property(strong,nonatomic)NSArray<NSString *> *dpFailArray;

/// dp尝试唤起监测
@property(strong,nonatomic)NSArray<NSString *> *dpTryArray;

/// ⼩程序唯⼀标识
@property(strong,nonatomic)NSString *wxId;

/// ⼩程序跳转路径
@property(strong,nonatomic)NSString *wxPath;

/// 素材宽
@property(assign,nonatomic)NSInteger w;

/// 素材⾼
@property(assign,nonatomic)NSInteger h;

/// 素材地址
@property(strong,nonatomic)NSArray<NSString *> *imageURLListArray;

/// 标题
@property(strong,nonatomic)NSString *title;

/// 副标题
@property(strong,nonatomic)NSString *desc;

/// 下载appname
@property(strong,nonatomic)NSString *appName;

/// 下载app包名
@property(strong,nonatomic)NSString *appBundle;

/// 下载appicon
@property(strong,nonatomic)NSString *appIcon;

/// 下载app版本
@property(strong,nonatomic)NSString *appVer;

/// 下载地址
@property(strong,nonatomic)NSString *appDownLoadURL;

/// 下载app开发者
@property(strong,nonatomic)NSString *appDeveloper;

/// 是否是⼴点通
@property(assign,nonatomic)NSInteger isgdt;

/// 下载app隐私政策
@property(strong,nonatomic)NSString *appPrivatePolicy;

/// 下载权限链接
@property(strong,nonatomic)NSString *appPermissionsLink;

/// 下载开始上报链接
@property(strong,nonatomic)NSArray<NSString *> *appDownStartListArray;

/// 下载完成上报链接
@property(strong,nonatomic)NSArray<NSString *> *appDownEndListArray;

/// 下载安装开始上报链接
@property(strong,nonatomic)NSArray<NSString *> *appInstallStartListArray;

/// 下载安装完成上报链接
@property(strong,nonatomic)NSArray<NSString *> *appInstallEndListArray;

/// 视频播放地址
@property(strong,nonatomic)NSString *videoURL;

/// 视频播放前封⽚
@property(strong,nonatomic)NSString *coverURL;

/// 视频播放时间单位秒
@property(assign,nonatomic)NSInteger duration;

/// 视频播放完成封⽚
@property(strong,nonatomic)NSString *endImageURL;

/// 视频播放跳过上报链接
@property(strong,nonatomic)NSArray<NSString *> *skipTracksArray;

/// 视频播放暂停上报链接
@property(strong,nonatomic)NSArray<NSString *> *pauseTracksArray;

/// 视频播放停⽌上报链接
@property(strong,nonatomic)NSArray<NSString *> *stopTracksArray;

/// 视频播放开始上报链接
@property(strong,nonatomic)NSArray<NSString *> *startTracksArray;

/// 视频播放1/4上报链接
@property(strong,nonatomic)NSArray<NSString *> *fristQuarterTracksArray;

/// 视频播放1/2上报链接
@property(strong,nonatomic)NSArray<NSString *> *middleTracksArray;

/// 视频播放3/4上报链接
@property(strong,nonatomic)NSArray<NSString *> *thirdQuarterTracksArray;

/// 视频播放完成上报链接
@property(strong,nonatomic)NSArray<NSString *> *completeTrackArray;

@end

NS_ASSUME_NONNULL_END

