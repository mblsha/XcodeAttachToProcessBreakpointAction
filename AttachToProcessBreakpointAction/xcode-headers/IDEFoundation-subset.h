//
//  IDEFoundation-subset.h
//  AttachToProcessBreakpointAction
//
//  Created by Michail Pishchagin on 15.02.15.
//  Copyright (c) 2015 mblsha. All rights reserved.
//

#ifndef AttachToProcessBreakpointAction_IDEFoundation_subset_h
#define AttachToProcessBreakpointAction_IDEFoundation_subset_h

@class DVTTextDocumentLocation;
@class IDEConsoleAdaptor;
@class IDELaunchSession;
@class IDEBreakpoint;

@protocol IDEDebugNavigableModel <NSObject>
@property(readonly) IDELaunchSession *launchSession;
@property(readonly, copy) NSString *associatedProcessUUID;
@end

@protocol IDEDebugProcess <IDEDebugNavigableModel>
@property(copy, nonatomic) NSString *name;
- (NSString *)contentDelegateUIExtensionIdentifier;

@optional
@property(readonly, nonatomic) NSArray *loadedCodeModules;
@end

@protocol IDEDebugSession <NSObject>
@property BOOL isDetached;
@property(getter=isProfilingSupported) BOOL profilingSupported;
@property(readonly, copy, nonatomic) DVTTextDocumentLocation *instructionPointerLocation;
@property BOOL hasCrashed;
@property long long exitCode;
@property BOOL hasExitCode;
@property(readonly) id <IDEDebugProcess> process;
@property(readonly) int coalescedState;
@property int state;
- (void)requestLoadDylibAtPath:(NSString *)arg1 completionBlock:(void (^)(NSError *))arg2;
- (struct _NSRange)rangeOfExpressionForFullTextAtPrompt:(NSString *)arg1;
- (BOOL)canContinueToLocation:(DVTTextDocumentLocation *)arg1 withinBlockAtRange:(struct _NSRange)arg2;
- (BOOL)consoleShouldTrackInputHistory;
- (BOOL)shouldAcceptFromDebugSession:(id <IDEDebugSession>)arg1 error:(id *)arg2;
- (BOOL)shouldRelinquishToDebugSession:(id <IDEDebugSession>)arg1 error:(id *)arg2;
- (void)evaluateExpression:(NSString *)arg1 threadID:(unsigned long long)arg2 stackFrameID:(unsigned long long)arg3 queue:(NSObject<OS_dispatch_queue> *)arg4 completionHandler:(void (^)(NSString *, NSString *))arg5;
- (void)evaluateExpression:(NSString *)arg1 threadID:(unsigned long long)arg2 stackFrameID:(unsigned long long)arg3 queue:(NSObject<OS_dispatch_queue> *)arg4 resultHandler:(void (^)(NSString *))arg5;
- (void)executeDebuggerCommand:(NSString *)arg1 threadID:(unsigned long long)arg2 stackFrameID:(unsigned long long)arg3;
- (void)requestFetchEvent;
- (void)requestDetach;
- (void)requestStop;
- (void)requestContinueToLocation:(DVTTextDocumentLocation *)arg1;
- (void)requestContinue;
- (void)requestPause;
- (void)requestStepOverSuspendOtherThreads;
- (void)requestStepInSuspendOtherThreads;
- (void)requestStepOverInstruction;
- (void)requestStepIntoInstruction;
- (void)requestStepOut;
- (void)requestStepOverLine;
- (void)requestStepIn;
@end

@interface IDEBreakpointActionEvaluationContext : NSObject
@property(readonly) unsigned long long selectedFrameIndex; // @synthesize selectedFrameIndex=_selectedFrameIndex;
@property(readonly) unsigned long long selectedThreadIndex; // @synthesize selectedThreadIndex=_selectedThreadIndex;
@property(readonly) IDEConsoleAdaptor *consoleAdaptor; // @synthesize consoleAdaptor=_consoleAdaptor;
@property(readonly) id <IDEDebugSession> debugSession; // @synthesize debugSession=_debugSession;
@end

@interface IDEBreakpointAction : NSObject
@property(copy) NSString *displayName;

- (id)initFromXMLUnarchiver:(id)arg1 archiveVersion:(float)arg2;
- (NSString*)expandExpressionsAndMacrosInString:(NSString*)arg1 usingBreakpoint:(IDEBreakpoint*)arg2;
@end

#endif
