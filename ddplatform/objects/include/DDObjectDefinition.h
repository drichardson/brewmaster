//
//  CObjectDefinition.h
//  CObjects
//
//  Created by Doug Richardson on 1/8/13.
//  Copyright (c) 2013 Doug Richardson. All rights reserved.
//

#ifndef CObjects_CObjectDefinition_h
#define CObjects_CObjectDefinition_h

#include "DDObjectBase.h"
#include <stdint.h>

struct CObjectDefinition;

struct CObjectDefinition* COCreate(size_t size, COTypeID typeID);
void CODestructor(struct CObjectDefinition*);

typedef struct CObjectDefinition
{
    int32_t referenceCount;
    COTypeID typeID;
    void (*destructor)(struct CObjectDefinition*);
} CObjectDefinition;

#endif
