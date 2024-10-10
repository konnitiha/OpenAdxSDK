//
//  OpenAdxAdProtocol.h
//  OpenAdx
//
//  Created by fyl on 2024/10/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol OpenAdxAdProtocol <NSObject>

- (void)win:(nullable NSDictionary*)ext;
- (void)loss:(nullable NSDictionary*)ext;

@end

NS_ASSUME_NONNULL_END
