typedef struct DynString {
    int len;    // string length
    int capacity;   // buffer length containing the string
    char *ps;   // pointer to the string
} DynString; 

