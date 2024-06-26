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

+ (instancetype)shareInstance;

/// SDK版本
+ (NSString *)sdkVersion;

///清除缓存
+ (void)clearCache;

/// 初始化方法
/// - Parameter appID: appid
+ (void)initWithAppID:(NSString *)appID;

/// 设置Debug模式
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
