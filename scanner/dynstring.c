#include "dynstring.h"

void dynstring_free(DynString * pstr) {
    if (pstr != NULL) {
        if (pstr->data) {
            free(pstr->data);
        pstr->count=0;
        pstr->capacity=0;
        }
    }
}

void dynstring_reset(DynString * pstr) {
    dynstring_free(pstr);



