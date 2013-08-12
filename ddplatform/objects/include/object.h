#pragma once

struct dd_object_class;

typedef struct {
    struct dd_object_class const* objectClass;
    int referenceCount;
} dd_object;


// The object class. The class hierarchy and instance methods (which are shared across all
// instances of the same class) are stored here.
typedef struct dd_object_class {
    struct dd_object_class const* parent;

    // method table
    struct dd_object_class const* (*object_class)(void);
    void (*initialize)(dd_object);
    void (*finalize)(dd_object);
    dd_object (*retain)(dd_object);
    void (*release)(dd_object);
    bool (*is_equal)(dd_object, dd_object);
    bool (*is_kind_of)(dd_object, dd_object);
} dd_object_class;

dd_object_class* dd_get_object_class(void);

// Allocates size bytes (zeroed). Sets the reference count to 1.
dd_object dd_object_allocate(size_t size, dd_object_class const*);

// Initializes an instance of dd_object.
dd_object dd_object_initialize(dd_object);

dd_object dd_retain(dd_object);
void dd_release(dd_object);

