#ifndef COARRAY_H_
#define COARRAY_H_

#include "CObjectBase.h"

typedef COTypeRef COArrayRef;

extern COTypeID COArrayTypeID;

// Immutable array methods

// Create a COArrayRef from an array of items. Each item will be retained. Ownership
// of items is NOT transfered to the COArrayRef.
COArrayRef COCreateArray(COTypeRef* items, unsigned itemCount);

// Create a COArrayRef from an array of items. Each item will be retained. Ownership
// of items is transfered to the COArrayRef.
COArrayRef COCreateArrayNoCopy(COTypeRef* items, unsigned itemCount);

unsigned COArrayGetLength(COArrayRef);
COTypeRef COArrayGetObjectAtIndex(COArrayRef, unsigned);

#endif