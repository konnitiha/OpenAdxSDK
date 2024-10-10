//
//  OpenAdxEventsRepoter.h
//  OpenAdx
//
//  Created by fyl on 2024/5/10.
//

#import <Foundation/Foundation.h>
/**
 事件名称：
 10：展示
 11：点击
 20：deeplink 尝试
 21：deeplink 成功
 22：deeplink 失败
 30：开始下载
 31：下载完成
 32：下载失败
 33：开始安装
 34：安装完成
 40：安装失败
 35：监测已安装
 36：监测未安装（deeplink唤起失败返回ActivityNotFoundException异常，由此可判断唤起失败的原因是app未安装）
 37：应用激活(应用打开)
 38：唤起微信小程序时上报
 39：安卓下载, 下载类型为优先应用市场时, 跳转到应用市场上报
 50：打开 landing 地址上报
 100：视频开始播放
 101：视频播放四分之一
 102：视频播放一半
 103：视频播放四分之三
 104：视频播放完成
 105：视频关闭
 106：视频全屏
 107：视频退出全屏
 108：视频静音
 109：视频退出静音
 110：视频暂停
 111：视频取消暂停
 112：视频自动播放
 113：视频跳过
 114：视频加载完成
 115：视频播放出错（加载失败）
 116：重复播放视频
 117：激励成功回调
 118：上滑事件
 119：下滑事件
 120：点击事件
 200：汇川预算，有单独说明，与其他上报不一样。请注意
 300：广告被关闭
 400：竞价胜出
 */
typedef enum : NSUInteger {
    OpenAdxEventsType_Exposure = 10,
    OpenAdxEventsType_Click = 11,
    OpenAdxEventsType_DeeplinkTry = 20,
    OpenAdxEventsType_DeeplinkSuccess = 21,
    OpenAdxEventsType_DeeplinkFail = 22,
    OpenAdxEventsType_AppStartDownload = 30,
    OpenAdxEventsType_AppFinishDownload = 31,
    OpenAdxEventsType_AppFailDownload = 32,
    OpenAdxEventsType_AppStartInstall = 33,
    OpenAdxEventsType_AppFinishInstall = 34,
    OpenAdxEventsType_AppFailInstall = 40,
    OpenAdxEventsType_AppMonitorInstall = 35,
    OpenAdxEventsType_AppMonitorNoInstall = 36,
    
    OpenAdxEventsType_AppOpen = 37,
    OpenAdxEventsType_WxProgramOpen = 38,
    OpenAdxEventsType_AppAndroidDownload = 39,
    
    OpenAdxEventsType_Landing = 50,
    
    OpenAdxEventsType_VideoStart = 100,
    OpenAdxEventsType_VideoFristQuarter = 101,
    OpenAdxEventsType_VideoMiddle = 102,
    OpenAdxEventsType_VideoThirdQuarter = 103,
    OpenAdxEventsType_VideoComplete = 104,
    OpenAdxEventsType_VideoClose = 105,
    OpenAdxEventsType_VideoFullScreen = 106,
    OpenAdxEventsType_VideoExitFullScreen = 107,
    OpenAdxEventsType_VideoMute = 108,
    OpenAdxEventsType_VideoExitMute = 109,
    OpenAdxEventsType_VideoPause = 110,
    OpenAdxEventsType_VideoResume= 111,
    OpenAdxEventsType_VideoAutoPlay= 112,
    OpenAdxEventsType_VideoSkip = 113,
    OpenAdxEventsType_VideoLoaded = 114,
    OpenAdxEventsType_VideoPlayError = 115,
    OpenAdxEventsType_VideoPlayAgain = 116,
    OpenAdxEventsType_VideoRewared = 117,
    OpenAdxEventsType_UserScrollUp = 118,
    OpenAdxEventsType_UserScrollDown = 119,
    OpenAdxEventsType_UserClick = 120,
    OpenAdxEventsType_HUICHUAN = 200,
    OpenAdxEventsType_Close = 300,
    OpenAdxEventsType_BidWin = 400,
} OpenAdxEventsType;


NS_ASSUME_NONNULL_BEGIN

@interface OpenAdxEventsRepoter : NSObject



/// 成交价 展现监测，winnotice，video-track
@property(assign,nonatomic)CGFloat __winprice__;
/**
 竞价id，即 Bid 中 的id
 展现监测，winnotice，video-track
 */
@property(copy,nonatomic)NSString *__BID_ID__;
/**
 请求id，即 Request 中 reqid
 展现监测，winnotice，video-track
 */
@property(copy,nonatomic)NSString *__REQUEST_ID__;
/**
 ImpID 曝光 ID，即 Request.Imp 中的impid
 展现监测，winnotice，video-track
 */
@property(copy,nonatomic)NSString *__IMP_ID__;
/**
 点击前缀，在落地页前面加上该宏，以便流量方可以监测到点击。同时要对落地页进行一次urlencode
 动态html素材
 */
@property(copy,nonatomic)NSString *__CLK_PRE__;

/**
 点击按下坐标x，若不支持则替换为-999，坐标单位为像素px，基于广告位
 点击按下坐标y，若不支持则替换为-999，坐标单位为像素px，基于广告位
 点击弹起坐标x，若不支持则替换为-999，坐标单位为像素px，基于广告位
 点击弹起坐标y，若不支持则替换为-999，坐标单位为像素px，基于广告位
 
 点击按下坐标x，若不支持则替换为-999，坐标单位为像素px，基于广告位
 点击按下坐标y，若不支持则替换为-999，坐标单位为像素px，基于广告位
 点击弹起坐标x，若不支持则替换为-999，坐标单位为像素px，基于广告位
 点击弹起坐标y，若不支持则替换为-999，坐标单位为像素px，基于广告位
 
 用户手指按下时的X坐标，广告位左上角为坐标原点 ，安卓端单位 dp，ios端单位 pt（逻辑像素，见下文）
 用户手指按下时的Y坐标，广告位左上角为坐标原点，安卓端单位 dp，ios端单位 pt（逻辑像素，见下文）
 ⽤户⼿指抬起时 x 坐标，⼴告位左上⾓作为坐标原点 ，安卓端单位 dp，ios端单位 pt（逻辑像素，见下文）
 ⽤户⼿指抬起时 y 坐标，⼴告位左上⾓作为坐标原点，安卓端单位 dp，ios端单位 pt（逻辑像素，见下文）
 
 点击监测，点击落地页，deeplink
 */

@property(assign,nonatomic)CGFloat __DOWN_X__;
@property(assign,nonatomic)CGFloat __DOWN_Y__;
@property(assign,nonatomic)CGFloat __UP_X__;
@property(assign,nonatomic)CGFloat __UP_Y__;

@property(assign,nonatomic)CGFloat __ABS_DOWN_X__;
@property(assign,nonatomic)CGFloat __ABS_DOWN_Y__;
@property(assign,nonatomic)CGFloat __ABS_UP_X__;
@property(assign,nonatomic)CGFloat __ABS_UP_Y__;

@property(assign,nonatomic)CGFloat __DP_DOWN_X__;
@property(assign,nonatomic)CGFloat __DP_DOWN_Y__;
@property(assign,nonatomic)CGFloat __DP_UP_X__;
@property(assign,nonatomic)CGFloat __DP_UP_Y__;


/// 实际广告位的宽，单位为像素px 各事件
@property(assign,nonatomic)CGFloat __WIDTH__;

/// 实际广告位的高，单位为像素px 各事件
@property(assign,nonatomic)CGFloat __HEIGHT__;

/// 实际广告位的宽，取逻辑像素值，安卓端单位 dp，ios端单位 pt  逻辑像素(dp) = 物理像素(px) / 屏幕密度(dpi)
@property(assign,nonatomic)CGFloat __DP_AD_WIDTH__;

/// 实际广告位的高，取逻辑像素值，安卓端单位 dp，ios端单位 pt 逻辑像素(dp) = 物理像素(px) / 屏幕密度(dpi)
@property(assign,nonatomic)CGFloat __DP_AD_HEIGHT__;



/// 事件开始时间（单位毫秒）    各事件
@property(assign,nonatomic)NSInteger __TMS_START__;

/// 事件开始时间（单位秒）    各事件
@property(assign,nonatomic)NSInteger __TS_START__;

/// 事件结束时间（单位毫秒）    各事件
@property(assign,nonatomic)NSInteger __TMS_END__;

/// 事件结束时间（单位秒）    各事件
@property(assign,nonatomic)NSInteger __TS_END__;


/**
 广点通id
 广点通预算
 */
@property(copy,nonatomic)NSString *__gdt_click_id__;


/**
 是否用 deeplink 唤醒，
 1 - 打开 deeplink
 2 - 打开落地页
 3 - 点击无效
 各事件
 */
@property(assign,nonatomic)int __DPLINK__;
/**
 deeplink 调起结果
 0 - 成功
 1 - 失败
 各事件
 */
@property(assign,nonatomic)int __DP_RESULT__;
/**
 点击区域：
 1 - 广告素材
 2 - 按钮
 各事件
 */
@property(assign,nonatomic)int __CLICKAREA__;

/**
 下载阶段：1-开始下载，2-下载完成，3-开始安装， 4-安装完成 vivo 必须替换
 下载、安装
 */
@property(assign,nonatomic)int __DLD_PHASE__;
/**
 转化行为类型
 1：开始下载
 2：安装完成
 3：下载完成
 各事件
 */
@property(assign,nonatomic)int __ACTION_ID__;

/**
 广告交互方式：
 0 - 常规触屏点击
 1 - 滑动点击
 2 - 摇一摇
 3 - 自定义手势
 5 - 扭一扭
 6 - 擦除
 其他的方式都按照 3 提交
 对于既支持摇一摇也支持点击或者既支持滑动也支持点击等多交互场景，以最终发生的交互行为为准进行上报
 点击监测，点击落地页
 */
@property(assign,nonatomic)int __SLD__;

/**
 当SLD=2时必填    用户摇动点击时x轴加速度峰值。Android端乘以100取整，iOS端乘以980取整。
 点击监测，点击落地页
 */
@property(assign,nonatomic)int __X_MAX_ACC__;
/**
 当SLD=2时必填    用户摇动点击时x轴加速度峰值。Android端乘以100取整，iOS端乘以980取整。
 点击监测，点击落地页
 */
@property(assign,nonatomic)int __Y_MAX_ACC__;
/**
 当SLD=2时必填    用户摇动点击时x轴加速度峰值。Android端乘以100取整，iOS端乘以980取整。
 点击监测，点击落地页
 */
@property(assign,nonatomic)int __Z_MAX_ACC__;

/**
 \当SLD=5时必填    对比扭动前初始位置，扭动触发点击时的x轴扭动角度，为-180到180的整数。
 点击监测，点击落地页
 */
@property(assign,nonatomic)int __TURN_X__;
/**
 对比扭动前初始位置，扭动触发点击时的y轴扭动角度，为-180到180的整数。
 点击监测，点击落地页
 */
@property(assign,nonatomic)int __TURN_Y__;

/**
 当SLD=5时必填    对比扭动前初始位置，扭动触发点击时的z轴扭动角度，为-180到180的整数。
 点击监测，点击落地页
 */
@property(assign,nonatomic)int __TURN_Z__;

/**
 当SLD=5时必填    扭动触发点击时扭动的总时间（单位毫秒，保留整数）。即最后一次监听到3个方向扭动角度均小于±5度，到点击触发的时间。
 点击监测，点击落地页
 */
@property(assign,nonatomic)NSInteger __TURN_TIME__;


/// 按钮左上角X坐标(相对屏幕)
@property(assign,nonatomic)CGFloat __BT_LT_X__;

/// 按钮左上角Y坐标(相对屏幕)
@property(assign,nonatomic)CGFloat __BT_LT_Y__;

/// 按钮右下角X坐标(相对屏幕)
@property(assign,nonatomic)CGFloat __BT_RB_X__;

/// 按钮右下角Y坐标(相对屏幕)
@property(assign,nonatomic)CGFloat __BT_RB_Y__;

/// ⼴告展⽰区域左上角X坐标(相对屏幕)
@property(assign,nonatomic)CGFloat __IMP_X1__;

/// ⼴告展⽰区域左上角Y坐标(相对屏幕)
@property(assign,nonatomic)CGFloat __IMP_Y1__;

/// ⼴告展⽰区域右下角X坐标(相对屏幕)
@property(assign,nonatomic)CGFloat __IMP_X2__;

/// ⼴告展⽰区域右下角Y坐标(相对屏幕)
@property(assign,nonatomic)CGFloat __IMP_Y2__;

/// 广告左上角坐标 x
@property(assign,nonatomic)CGFloat __AD_LT_X__;

/// 广告左上角坐标 y
@property(assign,nonatomic)CGFloat __AD_LT_Y__;

/// 广告右下角坐标 x
@property(assign,nonatomic)CGFloat __AD_RB_X__;

/// 广告右下角坐标 y
@property(assign,nonatomic)CGFloat __AD_RB_Y__;


/// 视频总时长， 单位秒
@property(assign,nonatomic)CGFloat __VIDEO_TIME__;

/// 视频播放事件触发时播放时长（单位秒）
@property(assign,nonatomic)CGFloat __VIDEO_PLAY_TS__;

/// 视频播放事件触发时播放时长（单位毫秒）
@property(assign,nonatomic)CGFloat __VIDEO_PLAY_MS__;

/// 视频播放开始时间， 单位为秒。 如果视频从头开始播放， 则为 0。
@property(assign,nonatomic)CGFloat __BEGIN_TIME__;

/// 视频播放进度， 单位为秒。 如果视频播放到结尾， 则等于视频总时长
@property(assign,nonatomic)CGFloat __END_TIME__;

/// 视频是否从第⼀帧开始播放。 从第⼀帧开始播放， 则为 1； 否则， 为0。
@property(assign,nonatomic)int __PLAY_FIRST_FRAME__;

/// 视频是否播放到最后⼀帧。 播放到最后⼀帧， 则为 1； 否则， 为 0
@property(assign,nonatomic)int __PLAY_LAST_FRAME__;

/// 视频播放进度，单位秒
@property(assign,nonatomic)CGFloat __PROGRESS_TS__;

/// 视频播放进度，单位毫秒
@property(assign,nonatomic)CGFloat __PROGRESS_TMS__;

/**
 播放场景。
 1 -在广告曝光区域播放;
 2 - 全屏竖屏、 只展示视频;
 3 - 全屏竖屏、 屏幕上方展示 视频、 下方展示广告推广目标 网页(参考附
 录广告渲染样式 示例，仅适用于交互类型是打开网页的广告， 目标网页由点击上报返回数据中取得， 详见 点击上报响应数据部分);
 4 - 全屏横屏、 只展示视频;
 0 - 其它开发者自定义场景
 */
@property(assign,nonatomic)int __SCENE__;

/**
 播放类型。
 1 - 第⼀次播放；
 2 - 暂停后继续播放；
 3 - 重新开始播放
 */
@property(assign,nonatomic)int __TYPE__;

/**
 播放⾏为。
 1 - ⾃动播放（推荐联⽹⽅式为 wififi 或 4G 时， 设置视频⾃动播放）
 2 - 点击播放。
 */
@property(assign,nonatomic)int __BEHAVIOR__;
/**
 播放状态。
 0 - 正常播
 1 - 视频加载中
 2 - 播放错误
 */
@property(assign,nonatomic)int __STATUS__;


/**
 点击动作类型
 0:未知
 1:正常点击，即常规触屏点击
 2:摇一摇
 3:划动点击
 */
@property(assign,nonatomic)int __CLICK_MODE__;
/**
 设备摇动时，x 轴加速度 单位:m/s2
 用户摇动点击时 x 轴加速度峰值 100 倍取
 整;仅广告交互方式=2(摇一摇)时替换
 */
@property(assign,nonatomic)CGFloat __SHAKE_X_MAX_ACC__;
/**
 设备摇动时，y 轴加速度 单位:m/s2
 用户摇动点击时 y 轴加速度峰值 100 倍取
 整;仅广告交互方式=2(摇一摇)时替换
 */
@property(assign,nonatomic)CGFloat __SHAKE_Y_MAX_ACC__;
/**
 设备摇动时，z 轴加速度 单位:m/s2 用户
 摇动点击时 z 轴加速度峰值 100 倍取整;
 仅广告交互方式=2(摇一摇)时替换
 */
@property(assign,nonatomic)CGFloat __SHAKE_Z_MAX_ACC__;



@property(strong,nonatomic)NSDate *clickTimeDate;
//以下废弃
/*
@property(assign,nonatomic)CGFloat clickX;
@property(assign,nonatomic)CGFloat clickY;
@property(assign,nonatomic)CGFloat clickUpX;
@property(assign,nonatomic)CGFloat clickUPY;

@property(assign,nonatomic)CGFloat clickAbsX;
@property(assign,nonatomic)CGFloat clickAbsY;
@property(assign,nonatomic)CGFloat clickAbsUpX;
@property(assign,nonatomic)CGFloat clickAbsUpY;


@property(strong,nonatomic)NSDate *clickTimeDate;
@property(assign,nonatomic)CGFloat clickTime;
@property(assign,nonatomic)CGFloat clickTimeS;


@property(assign,nonatomic)CGFloat width;
@property(assign,nonatomic)CGFloat height;
@property(assign,nonatomic)int videoBeginTime;
@property(assign,nonatomic)int videoEndTime;
@property(assign,nonatomic)bool videoFirstTime;
@property(assign,nonatomic)bool videoLastTime;
@property(assign,nonatomic)int videoScene;
@property(assign,nonatomic)int videoType;
@property(assign,nonatomic)int videoBeavior;
@property(assign,nonatomic)int videoStatus;

*/
@end

NS_ASSUME_NONNULL_END
