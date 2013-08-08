#include "COArray.h"
#include "CObjectDefinition.h"
#include "COException.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

COTypeID COArrayTypeID = "COArray";

typedef struct CArrayDefinition
{
	CObjectDefinition base;
	COTypeRef* items;
	unsigned length;
} CArrayDefinition;

static void COArrayDestructor(CObjectDefinition* array);

static COArrayRef COCreateArrayInternal(COTypeRef* items, unsigned itemCount, bool copy)
{
	CArrayDefinition* result = (CArrayDefinition*)COCreate(sizeof(CArrayDefinition), COArrayTypeID);
	result->base.destructor = COArrayDestructor;

	if ( copy )
	{
		// Make a copy of the array.
		unsigned length = sizeof(COTypeRef) * itemCount;
		result->items = malloc(length);
		memcpy(result->items, items, length);
	}
	else
	{
		result->items = items;
	}

	result->length = itemCount;

	// Retain each item in the array.
	for(unsigned int i = 0; i < itemCount; ++i)
	{
		COTypeRef o = COArrayGetObjectAtIndex(result, i);
		CORetain(o);
	}

	return (COArrayRef)result;
}

COArrayRef COCreateArray(COTypeRef* items, unsigned itemCount)
{
	return COCreateArrayInternal(items, itemCount, true);
}

COArrayRef COCreateArrayNoCopy(COTypeRef* items, unsigned itemCount)
{
	return COCreateArrayInternal(items, itemCount, false);
}

static void COArrayDestructor(CObjectDefinition* obj)
{
	CArrayDefinition* array = (CArrayDefinition*)obj;

	if ( array->items )
	{
		// Release each item in the array.
		for(unsigned int i = 0; i < array->length; ++i)
		{
			COTypeRef o = COArrayGetObjectAtIndex(array, i);
			CORelease(o);
		}

		free(array->items);
	}

	CODestructor(obj);
}

unsigned COArrayGetLength(COArrayRef arrayRef)
{
	CArrayDefinition* array = (CArrayDefinition*)arrayRef;
	return array->length;
}

COTypeRef COArrayGetObjectAtIndex(COArrayRef arrayRef, unsigned index)
{
	CArrayDefinition* array = (CArrayDefinition*)arrayRef;

	if ( index >= array->length )
	{
		COException("Array index out of bounds. Requested %u of %u", index, array->length);
	}

	return array->items[index];
}
