//
//  OpenAdxEventsRepoter.h
//  OpenAdx
//
//  Created by fyl on 2024/5/10.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    OpenAdxEventsType_Click = 1,
    OpenAdxEventsType_Exposure,
    OpenAdxEventsType_Landing,
    OpenAdxEventsType_DeeplinkSuccess,
    OpenAdxEventsType_DeeplinkFail,
    OpenAdxEventsType_DeeplinkTry,
    OpenAdxEventsType_VideoSkip,
    OpenAdxEventsType_VideoPause,
    OpenAdxEventsType_VideoStop,
    OpenAdxEventsType_VideoStart,
    OpenAdxEventsType_VideoFristQuarter,
    OpenAdxEventsType_VideoMiddle,
    OpenAdxEventsType_VideoThirdQuarter,
    OpenAdxEventsType_VideoComplete,
} OpenAdxEventsType;


NS_ASSUME_NONNULL_BEGIN

@interface OpenAdxEventsRepoter : NSObject

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


@property(assign,nonatomic)CGFloat videoTime;
@property(assign,nonatomic)int videoBeginTime;
@property(assign,nonatomic)int videoEndTime;
@property(assign,nonatomic)bool videoFirstTime;
@property(assign,nonatomic)bool videoLastTime;
@property(assign,nonatomic)int videoScene;
@property(assign,nonatomic)int videoType;
@property(assign,nonatomic)int videoBeavior;
@property(assign,nonatomic)int videoStatus;


@end

NS_ASSUME_NONNULL_END
