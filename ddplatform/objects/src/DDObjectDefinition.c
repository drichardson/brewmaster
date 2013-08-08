//
//  CObjectDefinition.c
//  CObjects
//
//  Created by Doug Richardson on 1/8/13.
//  Copyright (c) 2013 Doug Richardson. All rights reserved.
//


#include "DDObjectDefinition.h"
#include <stdlib.h>

CObjectDefinition* COCreate(size_t size, COTypeID typeID)
{
    CObjectDefinition* result = (struct CObjectDefinition*)malloc(size);
    result->referenceCount = 1;
    result->typeID = typeID;
    result->destructor = CODestructor;
    
    return result;
}

void CODestructor(CObjectDefinition* o)
{
    free(o);
}
