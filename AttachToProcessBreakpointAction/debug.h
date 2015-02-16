//
//  debug.h
//  AttachToProcessBreakpointAction
//
//  Created by Michail Pishchagin on 15.02.15.
//  Copyright (c) 2015 mblsha. All rights reserved.
//

#ifndef AttachToProcessBreakpointAction_debug_h
#define AttachToProcessBreakpointAction_debug_h

#define CHECK(x)                                                             \
  do {                                                                       \
    if (!(x)) {                                                              \
      fprintf(stderr, "Check %s failed at %s:%d\n", #x, __FILE__, __LINE__); \
      exit(1);                                                               \
    }                                                                        \
  } while (0)

#endif
