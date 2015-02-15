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

@interface DVTXMLArchiver : NSObject

+ (id)archivedDataWithRootObject:(id)arg1;
+ (void)setElementNamePrefix:(id)arg1;
+ (id)elementNameForClass:(Class)arg1;
+ (void)setElementName:(id)arg1 forClass:(Class)arg2;
@property(retain) id context; // @synthesize context=_context;
- (void)_encodeExtraRelationshipsForObject:(id)arg1;
- (void)_finishEncodingAttributes;
- (void)_beginEncodingAttributesForObject:(id)arg1;
- (void)_didEncodeAttributeWithName:(id)arg1;
- (void)finishEncoding;
- (void)encodeIntegerAttribute:(id)arg1 withValue:(long long)arg2;
- (void)encodeBoolAttribute:(id)arg1 withValue:(BOOL)arg2;
- (void)encodeStringAttribute:(id)arg1 withValue:(id)arg2;
- (void)encodeObjectArray:(id)arg1 withTagName:(id)arg2;
- (void)encodeRootObjectArray:(id)arg1 withTagName:(id)arg2 archiveVersion:(id)arg3;
- (void)_encodeObjectArray:(id)arg1 withTagName:(id)arg2 archiveVersion:(id)arg3;
- (void)encodeObject:(id)arg1;
- (void)encodeRootObject:(id)arg1 withArchiveVersion:(id)arg2;
- (void)_encodeVersionAttribute:(id)arg1;
- (id)xmlWriter;
- (id)elementNameForClass:(Class)arg1;
- (void)setElementName:(id)arg1 forClass:(Class)arg2;
- (id)delegate;
- (void)setDelegate:(id)arg1;
- (id)init;
- (id)initForWritingWithMutableData:(id)arg1;
@end

@interface DVTXMLUnarchiver : NSObject
+ (BOOL)unarchiveData:(id)arg1 withRootObject:(id)arg2 error:(id *)arg3;
+ (id)unarchiveObjectWithData:(id)arg1;
+ (void)setElementNamePrefix:(id)arg1;
+ (Class)classForElementName:(id)arg1;
+ (void)setClass:(Class)arg1 forElementName:(id)arg2;
+ (void)initialize;
@property(copy) NSError *xmlParserError; // @synthesize xmlParserError=_xmlParserError;
@property(copy) NSError *decodingError; // @synthesize decodingError=_decodingError;
//@property(retain, nonatomic) id <DVTXMLUnarchiverDelegate> delegate; // @synthesize delegate=_delegate;
@property BOOL archiveContainedUnsupportedNodes; // @synthesize archiveContainedUnsupportedNodes=_archiveContainedUnsupportedNodes;
//@property(copy) CDUnknownBlockType versionChecker; // @synthesize versionChecker=_versionChecker;
@property(retain) id context; // @synthesize context=_context;
- (id)_corruptedDocumentErrorWithUnderlyingErrorCode:(unsigned long long)arg1 reason:(id)arg2;
- (id)_genericUnreadableDocumentError;
- (void)finishDecoding;
- (BOOL)decodeWithRootObject:(id)arg1 error:(id *)arg2;
- (id)decodeRootObject;
- (BOOL)_readAndReturnError:(id *)arg1;
//- (BOOL)decodeNodeWithXMLTextReader:(struct _xmlTextReader *)arg1 owner:(id)arg2 container:(id)arg3 parsingState:(id)arg4 error:(id *)arg5;
//- (id)decodeElementNodeWithXMLTextReader:(struct _xmlTextReader *)arg1 owner:(id)arg2 container:(id)arg3 parsingState:(id)arg4 success:(char *)arg5 error:(id *)arg6;
//- (Class)classForUnarchivedObjectFromElementNodeWithXMLTextReader:(struct _xmlTextReader *)arg1 owner:(id)arg2;
- (void)setRootObject:(id)arg1;
- (Class)classForElementName:(id)arg1;
- (void)setClass:(Class)arg1 forElementName:(id)arg2;
- (id)init;
- (id)initForReadingWithData:(id)arg1;
@end

@interface DVTProcessInformation : NSObject
- (id)initWithPID:(int)arg1;
@property(readonly) NSString *preferredArchitecture; // @synthesize preferredArchitecture=_preferredArchitecture;
@property(readonly) NSURL *processURL; // @synthesize processURL=_processURL;
@property(readonly) NSString *displayName; // @synthesize displayName=_displayName;
@property(readonly) int pid; // @synthesize pid=_pid;
@property(readonly) BOOL isDebuggable;
@end

@interface DVTLocalProcessInformation : DVTProcessInformation
+ (id)currentProcessInformations;
@property(copy, nonatomic) NSString *firstApplicationArgument; // @synthesize firstApplicationArgument=_firstApplicationArgument;
@property(copy, nonatomic) NSString *requestedApplicationName; // @synthesize requestedApplicationName=_requestedApplicationName;
@property(copy, nonatomic) NSString *realApplicationName; // @synthesize realApplicationName=_realApplicationName;
@end

#endif
