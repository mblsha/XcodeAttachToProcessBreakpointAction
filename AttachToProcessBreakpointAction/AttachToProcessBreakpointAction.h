//
//  AttachToProcessBreakpointAction.h
//  AttachToProcessBreakpointAction
//
//  Created by Michail Pishchagin on 15.02.15.
//  Copyright (c) 2015 mblsha. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "xcode-headers/IDEFoundation-subset.h"
#import "xcode-headers/DVTFoundation-subset.h"

@interface AttachToProcessBreakpointAction : IDEBreakpointAction
@property(copy) NSString *consoleCommand;

+ (id)propertiesAffectingPersistenceState;
- (void)dvt_encodeAttributesWithXMLArchiver:(id)arg1 version:(id)arg2;
- (void)performActionUsingContext:(id)arg1 andBreakpoint:(id)arg2;

- (id)init;
- (id)initFromXMLUnarchiver:(DVTXMLUnarchiver*)arg1 archiveVersion:(float)arg2;
- (void)_debuggerCommandActionCommonInit;
@end

@interface AttachToProcessBreakpointActionEditor : NSViewController
- (id)initWithAction:(IDEBreakpointAction*)action;
@end
