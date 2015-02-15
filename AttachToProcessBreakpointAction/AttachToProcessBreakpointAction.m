//
//  AttachToProcessBreakpointAction.m
//  AttachToProcessBreakpointAction
//
//  Created by Michail Pishchagin on 15.02.15.
//  Copyright (c) 2015 mblsha. All rights reserved.
//

#import "AttachToProcessBreakpointAction.h"
#import "AttachToProcessBreakpointActionPlugin.h"
#import "xcode-headers/DVTFoundation-subset.h"
#import "xcode-headers/IDEKit-subset.h"
#import "debug.h"

@implementation AttachToProcessBreakpointAction
- (instancetype)init {
  if ((self = [super init])) {
    [self _debuggerCommandActionCommonInit];
  }
  return self;
}

- (void)_debuggerCommandActionCommonInit {
  [self setDisplayName:@"Attach To Process"];
}

- (void)attachToProcess:(NSString*)pidString {
  NSLog(@"attachToProcess: %@", pidString);
  int pid = [pidString intValue];
  if (!pid)
    return;

  DVTLocalProcessInformation* proc = nil;
  for (DVTLocalProcessInformation* p in [DVTLocalProcessInformation currentProcessInformations]) {
    if ([p pid] == pid) {
      proc = p;
      break;
    }
  }
  if (!proc)
    return;

  IDEWorkspaceWindowController *workspaceController =
      [IDEWorkspaceWindow lastActiveWorkspaceWindowController];
  CHECK(workspaceController);
  IDEWorkspaceTabController *workspaceTabController =
      [workspaceController activeWorkspaceTabController];
  CHECK(workspaceTabController);

  id result = [IDEAttachToProcessHelper attachToProcess:proc fromWorkspaceTabController:workspaceTabController];
  CHECK(result);
}

- (void)performActionUsingContext:(IDEBreakpointActionEvaluationContext*)context andBreakpoint:(IDEBreakpoint*)breakpoint {
  id<IDEDebugSession> debugSession = [context debugSession];
  CHECK(debugSession);
  [debugSession evaluateExpression:self.consoleCommand
                          threadID:[context selectedThreadIndex]
                      stackFrameID:[context selectedFrameIndex]
                             queue:dispatch_get_main_queue()
                 completionHandler:^(NSString* result, NSString* s2) {
                   [self attachToProcess:result];
                 }];

//  [debugSession executeDebuggerCommand:[self consoleCommand]
//                              threadID:[context selectedThreadIndex]
//                          stackFrameID:[context selectedFrameIndex]];
}

+ (NSArray*)propertiesAffectingPersistenceState {
  return @[ @"consoleCommand" ];
}

- (instancetype)initFromXMLUnarchiver:(DVTXMLUnarchiver*)unarchiver archiveVersion:(float)version {
  if ((self = [super initFromXMLUnarchiver:unarchiver archiveVersion:version])) {
    [self _debuggerCommandActionCommonInit];
  }
  return self;
}

- (void)dvt_encodeAttributesWithXMLArchiver:(DVTXMLArchiver*)archiver version:(id)version {
  NSString* command = [self consoleCommand];
  if (command) {
    [archiver encodeStringAttribute:@"consoleCommand" withValue:command];
  }
}
@end

@implementation AttachToProcessBreakpointActionEditor
- (id)initWithAction:(AttachToProcessBreakpointAction*)action {
  NSBundle* bundle = [AttachToProcessBreakpointActionPlugin sharedPlugin].bundle;
  if ((self = [super initWithNibName:@"AttachToProcessBreakpointActionEditor" bundle:bundle])) {
    self.action = action;
  }
  return self;
}

- (void)awakeFromNib {
  if (self.action.consoleCommand) {
    [self.commandTextField setStringValue:self.action.consoleCommand];
  }
}

- (IBAction)commandDidChange:(id)sender {
  [self.action setConsoleCommand:[self.commandTextField stringValue]];
}
@end
