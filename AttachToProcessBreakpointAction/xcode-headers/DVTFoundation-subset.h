//
//  DVTFoundation-subset.h
//  AttachToProcessBreakpointAction
//
//  Created by Michail Pishchagin on 15.02.15.
//  Copyright (c) 2015 mblsha. All rights reserved.
//

#ifndef AttachToProcessBreakpointAction_DVTFoundation_subset_h
#define AttachToProcessBreakpointAction_DVTFoundation_subset_h

@class DVTPlugIn;

@interface DVTPlugInManager : NSObject
+ (id)defaultPlugInManager;
- (id)extensionPointWithIdentifier:(id)arg1;
@end

@interface DVTExtensionPoint : NSObject
@property(readonly, copy) NSSet *extensions; // @synthesize extensions=_extensions;
@property(readonly) DVTPlugIn *plugIn; // @synthesize plugIn=_plugIn;
@end

@interface DVTExtension : NSObject
- (id)initWithPropertyList:(id)arg1 owner:(id)arg2;
- (void)awakeWithPropertyList:(id)arg1;
@end

#endif
