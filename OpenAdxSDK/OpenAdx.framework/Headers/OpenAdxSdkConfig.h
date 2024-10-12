//
//  OpenAdxSdkConfig.h
//  cloooudsdk
//
//  Created by cloooud on 2019/9/12.
//  Copyright © 2019 fyl. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,OpenAdxLogLevel) {
    OpenAdxLogLevel_None  = 0, // 不打印
    OpenAdxLogLevel_Fatal,
    OpenAdxLogLevel_Error,
    OpenAdxLogLevel_Warning,
    OpenAdxLogLevel_Info,
    OpenAdxLogLevel_Debug,
};


@interface OpenAdxSdkConfig : NSObject

/// optional 禁止IDFA：0-不禁止，1-禁止，默认为0。只适用于GDT。
@property(nonatomic,strong)NSNumber *forbiddenIDFA;

/// optional 禁止地理位置：0-不禁止，1-禁止，默认为0。
@property(nonatomic,strong)NSNumber *forbiddenLocation;

/// optional 禁止采集设备信息:0-不禁止，1-禁止，默认为0。
@property(nonatomic,strong)NSNumber *forbiddenDeviceInfo;

/// optional 禁止 IDFA情况下,用户传入自定义字符串,透传给三方广告平台
@property(nonatomic,copy)NSString *customIDFA;


/// optional
/*
 当前手机上的安装app列表,一个字符串数组
 */
@property(nonatomic,strong)NSArray<NSString *> *appList;

/// optional
/*
 CAID 数组对象 数组元素为 dic 格式如下:
 @[@{
 @"caid":@"Caid id",
 @"version":@"Caid version"
 }];
 */
@property(nonatomic,strong)NSArray *CAIDList;

/// 获取单例
+ (instancetype)shareInstance;

/// SDK版本
+ (NSString *)sdkVersion;

///清除缓存
+ (void)clearCache;

/// 初始化方法
/// - Parameter appID: appid
+ (void)initWithAppID:(NSString *)appID;

/// 设置Debug模式,会改变 loglevel 级别,测试用,上线时一定改为 NO
/// - Parameter isDebug:  默认为 NO
+ (void)setDebugMode:(BOOL)isDebug;

/// debug 默认为 NO
@property(assign,nonatomic)BOOL isDebug;

/// 控制台log级别
/// 0 不打印
/// 1 打印fatal
/// 2 fatal + error
/// 3 fatal + error + warning
/// 4 fatal + error + warning + info
/// 5 全部打印
@property (nonatomic, assign) OpenAdxLogLevel level;

@end

NS_ASSUME_NONNULL_END
