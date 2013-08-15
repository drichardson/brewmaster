#include "class.h"
#include <stdlib.h>

typedef struct dd_class_impl {
    dd_class parentClass;
} dd_class_impl;


dd_class dd_new_class(dd_class parentClass) {
    dd_class_impl* result = (dd_class_impl*)malloc(sizeof(dd_class_impl));
    result->parentClass = parentClass;
    return result;
}

bool dd_is_kind_of(dd_class thisClass, dd_class otherClass) {
    for(; thisClass; thisClass = thisClass->parentClass) {
        if (thisClass == otherClass) {
            return true;
        }
    }
    return false;
}

