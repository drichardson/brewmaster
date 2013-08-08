#pragma once

#include <stdbool.h>

struct dd_class_impl;
typedef struct dd_class_impl const* dd_class;

// Create a new class. Once created, a class can not be removed. Pass NULL for parentClass
// if you are creating a root class.
dd_class dd_new_class(dd_class parentClass);

// Check if thisClass or one of it's parents is equal to otherClass.
bool dd_is_kind_of(dd_class thisClass, dd_class otherClass);

