#include <stdio.h>
#include "lex.h"

int ch;
int linenum = 0;

void preprocess() {
    ch = getc(fp);

    while (1) {
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (ch == '\n') {
                linenum++;
                ch = getc(fp);
            }
        }
        else if (ch == '/') {       // deal with comment
            ch = getc(fp);
            if (ch == '*') {
                parse_comment(fp);
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

/* Problem: the character is reading one by one, what the charcter is when you deal with
 */
void parse_comment(FILE *fp) {
    ch = getc(fp);
    while (1) {
        while (1) {
            if (ch == '\n' || ch == '*' || ch == EOF) {
                break;
            }
            else
                ch = getc(fp);
        }
        if (ch == '\n')
            ch = getc(fp);
        else if (ch == '*') {
            if ((ch = getc(fp)) == '/') {
                ch = getc(fp);
                return;
            }
        }
        else 
            printf("%s\n", "there is no end character '/' of the comment");
    }
}
