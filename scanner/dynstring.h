typedef struct DynString {
    int len;    // string length
    int capacity;   // buffer length containing the string
    char * data;   // pointer to the string
} DynString; 

void dynstring_reset(DynString *);
void dynstring_chcat(DynString *, char);



