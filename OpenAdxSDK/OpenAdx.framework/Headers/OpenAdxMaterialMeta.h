//
//  OpenAdxMaterialMeta.h
//  OpenAdx
//
//  Created by fyl on 2024/5/30.
//

#import <Foundation/Foundation.h>

@class OpenAdxResponseBid;
NS_ASSUME_NONNULL_BEGIN

@interface OpenAdxMaterialMeta : NSObject

/// 出价，单位⼈⺠币分
@property(assign,nonatomic,readonly,readonly)NSInteger price;

/// 0- ⽹⻚ 1- 下载
@property(assign,nonatomic,readonly)NSInteger action;

/// 点击落地⻚，如果是app下载，则为app下载地址。点击地址须优先使⽤deeplink，landing次之
@property(strong,nonatomic,readonly)NSString *landing;

/// ⼴告来源标识⽂字
@property(strong,nonatomic,readonly)NSString *source;

/// ⼴告来源标识的logo图⽚url
@property(strong,nonatomic,readonly)NSString *logo;

/// ⼩程序跳转路径
@property(strong,nonatomic,readonly)NSString *wxPath;

/// 素材宽
@property(assign,nonatomic,readonly)NSInteger w;

/// 素材⾼
@property(assign,nonatomic,readonly)NSInteger h;

/// 素材地址
@property(strong,nonatomic,readonly)NSArray<NSString *> *imageURLListArray;

/// 标题
@property(strong,nonatomic,readonly)NSString *title;

/// 副标题
@property(strong,nonatomic,readonly)NSString *desc;

/// 下载appname
@property(strong,nonatomic,readonly)NSString *appName;

/// 下载app包名
@property(strong,nonatomic,readonly)NSString *appBundle;

/// 下载appicon
@property(strong,nonatomic,readonly)NSString *appIcon;

/// 下载app版本
@property(strong,nonatomic,readonly)NSString *appVer;

/// 下载地址
@property(strong,nonatomic,readonly)NSString *appDownLoadURL;

/// 下载app开发者
@property(strong,nonatomic,readonly)NSString *appDeveloper;


/// 下载app隐私政策
@property(strong,nonatomic,readonly)NSString *appPrivatePolicy;

/// 下载权限链接
@property(strong,nonatomic,readonly)NSString *appPermissionsLink;

/// 视频播放地址
@property(strong,nonatomic,readonly)NSString *videoURL;

/// 视频播放前封⽚
@property(strong,nonatomic,readonly)NSString *coverURL;

/// 视频播放时间单位秒
@property(assign,nonatomic,readonly)NSInteger duration;

/// 视频播放完成封⽚
@property(strong,nonatomic,readonly)NSString *endImageURL;

- (instancetype)initWithResponseBid:(OpenAdxResponseBid *)resultData;
@end

NS_ASSUME_NONNULL_END
