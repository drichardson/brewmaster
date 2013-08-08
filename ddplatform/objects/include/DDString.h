#ifdef _COSTRING_H_
#define _COSTRING_H_

#include "CObjectBase.h"

typedef COTypeRef COStringRef;

extern COTypeID COStringTypeID;

// Immutable array methods

// If kArrayOptionsTakeOwnership is specified for options, items must be allocated
// with malloc. Use kArrayOptionsTakeOwnership to avoid an extra memory copy.
COStringRef COCreateStringWithUTF8String(const char* string);
COStringRef COCreateStringWithUTF8StringNoCopy(const char* string);

// Returns the number of characters (UTF-16 code pairs), not the number of bytes.
unsigned COStringGetLength(COStringRef);
COTypeRef COStringGetCharacterAtIndex(COArrayRef, unsigned);

#endif
