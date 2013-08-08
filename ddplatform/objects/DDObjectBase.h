//
//  CObjectBase.h
//  CObjects
//
//  Created by Doug Richardson on 1/8/13.
//  Copyright (c) 2013 Doug Richardson. All rights reserved.
//

#ifndef CObjects_CObjectBase_h
#define CObjects_CObjectBase_h

#include <stddef.h>

typedef const void* COTypeRef;

// Type IDs are char* so you can print them for debugging/logging. They must
// point to a string that will never be deallocated (e.g., a static string).
typedef const char* COTypeID;

void CORelease(COTypeRef);
void CORetain(COTypeRef);
COTypeID COGetTypeID(COTypeRef);

#endif
