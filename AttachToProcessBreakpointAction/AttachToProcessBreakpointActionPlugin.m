//
//  AttachToProcessBreakpointAction.m
//  AttachToProcessBreakpointAction
//
//  Created by Michail Pishchagin on 15.02.15.
//  Copyright (c) 2015 mblsha. All rights reserved.
//

#import "AttachToProcessBreakpointActionPlugin.h"
#import "xcode-headers/DVTFoundation-subset.h"

#define CHECK(x)                                                             \
do {                                                                       \
if (!(x)) {                                                              \
fprintf(stderr, "Check %s failed at %s:%d\n", #x, __FILE__, __LINE__); \
exit(1);                                                               \
}                                                                        \
} while (0)

static AttachToProcessBreakpointActionPlugin *sharedPlugin;

@interface AttachToProcessBreakpointActionPlugin()
@property (nonatomic, strong, readwrite) NSBundle *bundle;
@end

@implementation AttachToProcessBreakpointActionPlugin

+ (void)pluginDidLoad:(NSBundle *)plugin {
  static dispatch_once_t onceToken;
  NSString *currentApplicationName = [[NSBundle mainBundle] infoDictionary][@"CFBundleName"];
  if ([currentApplicationName isEqual:@"Xcode"]) {
    dispatch_once(&onceToken, ^{
      sharedPlugin = [[self alloc] initWithBundle:plugin];
    });
  }
}

+ (instancetype)sharedPlugin {
  return sharedPlugin;
}

- (id)initWithBundle:(NSBundle *)plugin {
  if (self = [super init]) {
    // reference to plugin's bundle, for resource access
    self.bundle = plugin;

    DVTPlugInManager* manager = DVTPlugInManager.defaultPlugInManager;
    CHECK(manager);
    DVTExtensionPoint* point = [manager extensionPointWithIdentifier:@"Xcode.IDEKit.IDEBreakpointActionEditor"];
    CHECK(point);
    NSMutableSet *extensions = (NSMutableSet*)[point extensions];
    CHECK(extensions);

    // we need some plugin to act as an owner for our extension
    DVTPlugIn* plugIn = [point plugIn];
    CHECK(plugIn);

    NSDictionary* plist = @{
      @"point": @"Xcode.IDEKit.IDEBreakpointActionEditor",

      @"id": @"Xcode.BreakpointActionEditor.AttachToProcess",
      @"name": @"AttachToProcess Breakpoint Action Editor",
      @"version": @"0.1",
      @"placement": @"bottom",

      @"breakpointActionClass": @"AttachToProcessBreakpointAction", // @"AttachToProcessBreakpointAction",
      @"controllerClass": @"IDEShellCommandBreakpointActionEditor", // @"AttachToProcessBreakpointActionEditor",
    };

    DVTExtension* extension = [[DVTExtension alloc] initWithPropertyList:plist owner:plugIn];
    [extension awakeWithPropertyList:plist];
    CHECK(extension);

    [extensions addObject:extension];

    // Create menu items, initialize UI, etc.
/*
    // Sample Menu Item:
    NSMenuItem *menuItem = [[NSApp mainMenu] itemWithTitle:@"Edit"];
    if (menuItem) {
      [[menuItem submenu] addItem:[NSMenuItem separatorItem]];
      NSMenuItem *actionMenuItem = [[NSMenuItem alloc] initWithTitle:@"Do Action" action:@selector(doMenuAction) keyEquivalent:@""];
      [actionMenuItem setTarget:self];
      [[menuItem submenu] addItem:actionMenuItem];
    }
*/
  }
  return self;
}

// Sample Action, for menu item:
- (void)doMenuAction {
  NSAlert *alert = [[NSAlert alloc] init];
  [alert setMessageText:@"Hello, World"];
  [alert runModal];
}

- (void)dealloc {
  [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
