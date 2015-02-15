//
//  IDEKit-subset.h
//  AttachToProcessBreakpointAction
//
//  Created by Michail Pishchagin on 15.02.15.
//  Copyright (c) 2015 mblsha. All rights reserved.
//

#ifndef AttachToProcessBreakpointAction_IDEKit_subset_h
#define AttachToProcessBreakpointAction_IDEKit_subset_h

@class IDEEditorArea;
@class IDEWorkspaceWindowController;

@interface IDEWorkspaceWindow : NSWindow
+ (IDEWorkspaceWindowController*)lastActiveWorkspaceWindowController;
@end

@interface IDEWorkspaceTabController : NSObject
@end

@interface IDEWorkspaceWindowController : NSWindowController
@property(readonly) IDEWorkspaceTabController *activeWorkspaceTabController;
@property(readonly) IDEWorkspaceWindow *workspaceWindow;
@property(readonly) IDEEditorArea *editorArea;
@end

@interface IDEAttachToProcessHelper : NSObject
+ (void)askUserForProcessIdentifierAndAttachToItFromWorkspaceTabController:(IDEWorkspaceTabController*)tab;
+ (id)attachToProcess:(DVTProcessInformation*)proc fromWorkspaceTabController:(IDEWorkspaceTabController*)tab usingRunDestination:(id)arg3 explicitActivityViewTitle:(id)arg4;
+ (id)attachToProcess:(DVTProcessInformation*)proc fromWorkspaceTabController:(IDEWorkspaceTabController*)tab usingRunDestination:(id)arg3;
+ (id)attachToProcess:(DVTProcessInformation*)proc fromWorkspaceTabController:(IDEWorkspaceTabController*)tab;
@end

#endif
