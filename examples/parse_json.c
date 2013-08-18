#include <jansson.h>
#include <stdio.h>

int main(int argc, char** argv) {
    json_error_t error;
    json_t* doc = json_load_file("test.json", 0, &error);
    if (doc == NULL) {
        fprintf(stderr, "couldn't load test.json: text: %s, source: %s, line: %d, column: %d, position: %d\n", error.text, error.source, error.line, error.column, error.position);
        exit(1);
    }

    if (!json_is_object(doc)) {
       fprintf(stderr, "doc isn't an object. It's a %d\n", json_typeof(doc)); 
       exit(1);
    }

    json_t* str = json_object_get(doc, "string");
    json_t* num = json_object_get(doc, "number");
    json_t* obj = json_object_get(doc, "object");
    json_t* arr = json_object_get(doc, "array");

    if (!json_is_string(str)) {
        fprintf(stderr, "didn't get expected string\n");
        exit(1);
    }
    if (!json_is_number(num)) {
        fprintf(stderr, "didn't get expected number\n");
        exit(1);
    }
    if (!json_is_object(obj)) {
        fprintf(stderr, "didn't get expected object\n");
        exit(1);
    }
    if (!json_is_array(arr)) {
        fprintf(stderr, "didn't get expected array\n");
        exit(1);
    }

    // that's enough type checking for one day, just go through this shit.
    printf("string value is %s\n", json_string_value(str)); 
    printf("number value is %f\n", json_real_value(num));
    
    puts("array: ");
    for(int i = 0, count = json_array_size(arr); i < count; ++i) {
        json_t* e = json_array_get(arr, i);
        printf("  %d: type: %d\n", i, json_typeof(e));
    }

    return 0;
}

