#include <stdio.h>
#include "lex.h"

int ch;


void preprocess() {
    ch = getc(fp);

    while (1) {
        if (ch == ' ' || ch == '\t' || ch == '\r') {
            skip_white_space();
        }
        else if (ch == '/') {       // deal with comment
            ch = getc(fp);
            if (ch == '*') {
                parseComment();
            }
            else {      // if the character is not a comment, push back the character
                ungetc(ch, fp);
                ch = '/';
                break;
            }
        }
        else 
            break;
    }
}


