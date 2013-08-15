//
//  CObjectBase.c
//  CObjects
//
//  Created by Doug Richardson on 1/8/13.
//  Copyright (c) 2013 Doug Richardson. All rights reserved.
//

#include "DDObjectBase.h"

#include <libkern/OSAtomic.h>
#include <stdlib.h>
#include <assert.h>
#include "DDObjectDefinition.h"

void CORelease(COTypeRef o)
{
    if ( o == NULL )
    {
        return;
    }
    
    CObjectDefinition* obj = (CObjectDefinition*)o;
    
    if ( OSAtomicDecrement32Barrier(&obj->referenceCount) == 0 )
    {
        if ( obj->destructor )
        {
            obj->destructor(obj);
        }
    }
}

void CORetain(COTypeRef o)
{
    if ( o == NULL )
    {
        return;
    }
    
    CObjectDefinition* obj = (CObjectDefinition*)o;
    
    OSAtomicIncrement32Barrier(&obj->referenceCount);
}

COTypeID COGetTypeID(COTypeRef o)
{
    if ( o == NULL )
    {
        return NULL;
    }

    CObjectDefinition* obj = (CObjectDefinition*)o;

    return obj->typeID;
}
