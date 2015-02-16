//
//  AttachToProcessBreakpointAction.h
//  AttachToProcessBreakpointAction
//
//  Created by Michail Pishchagin on 15.02.15.
//  Copyright (c) 2015 mblsha. All rights reserved.
//

#import <AppKit/AppKit.h>

@interface AttachToProcessBreakpointActionPlugin : NSObject

+ (instancetype)sharedPlugin;

@property(nonatomic, strong, readonly) NSBundle* bundle;
@end
