#include "object.h"

static struct dd_object_class const* object_class(void) {
    return dd_get_object_class();
}

static void (*initialize)(dd_object self) {
}

static void (*finalize)(dd_object self) {
    free(self);
}

static dd_object (*retain)(dd_object) {
    self->referenceCount++;
}

static void (*release)(dd_object) {
    self->referenceCount--;
    if (self->referenceCount == 0) {
        self->objectClass->finalize
    }
}

static bool (*is_equal)(dd_object self, dd_object other) {
    return self == other;
}

static bool (*is_kind_of)(dd_object self, dd_object other) {
}


dd_object_class* dd_get_object_class(void) {
    dd_object_class* object_class = NULL;
    // TODO: Make this thread safe.
    if (object_class == NULL) {
        object_class = (dd_object_class*)calloc(1, sizeof(dd_object_class));
        object_class->parent = NULL; // this is the root object
        object_class->initialize;

    }
}

dd_object dd_object_allocate(size_t size, dd_object_class const* objectClass) {
    dd_object o = (dd_object)calloc(1, size);
    o->objectClass = objectClass;
    o->referenceCount = 1;
    return o;
}

// Initializes an instance of dd_object.
dd_object dd_object_initialize(dd_object self) {
    return self;
}

dd_object dd_retain(dd_object self) {

}

void dd_release(dd_object) {
    self->referenceCount--;
    if (self->referenceCount == 0) {
        self->objectClass->finalize
    }
}

