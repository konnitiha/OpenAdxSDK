//
//  OpenAdxError.h
//  CloooudAPIAd
//
//  Created by fyl on 2024/4/24.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    OpenAdxErrorCode_SDK_UNINITIALIZED = 47000,
    OpenAdxErrorCode_SDK_INTERNAL = 47001,
    OpenAdxErrorCode_ILLEGAL_RESPONSE = 47002,
    OpenAdxErrorCode_REQUEST_TIMEOUTS =  40000,
    OpenAdxErrorCode_SERVER_ERROR = 40004,
    OpenAdxErrorCode_REQUEST_EINTR = 40002,
    OpenAdxErrorCode_APPLY_ID_EMPTY = 40003,
    OpenAdxErrorCode_AD_DATA_EMPTY = 40006,
} OpenAdxErrorCode;

NS_ASSUME_NONNULL_BEGIN

@interface OpenAdxError : NSError

+ (instancetype)errorWithCcode:(NSInteger)code msg:(NSString *)msg;
+ (instancetype)errorWithCcode:(NSInteger)code;
@end

NS_ASSUME_NONNULL_END
