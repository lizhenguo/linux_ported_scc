#include <stdio.h>
#include "lex.h"

int ch;
int linenum = 0;

/*
 * funcname: preprocess
 * function: deal with the space and comment before the program starts
 * para: none
 * return: none
 */
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
void parse_comment() {
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

/*
 * funcname: get_token
 * function: parse the character stream into token
 * implementation: deal with one character one by one
 * para: none
 * return: none
 */
void get_token() {
    preprocess();
    switch(ch) {
        case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':case 'g':
        case 'h':case 'i':case 'j':case 'k':case 'l':case 'm':case 'n':
        case 'o':case 'p':case 'q':case 'r':case 's':case 't':
        case 'u':case 'v':case 'w':case 'x':case 'y':case 'z':
        case 'A':case 'B':case 'C':case 'D':case 'E':case 'F':case 'G':
        case 'H':case 'I':case 'J':case 'K':case 'L':case 'M':case 'N':
        case 'O':case 'P':case 'Q':case 'R':case 'S':case 'T':
        case 'U':case 'V':case 'W':case 'X':case 'Y':case 'Z':
        case '_':
            {
                TkWord * tp;
                parse_identifier();
                tp = tkword_insert(tkstr.data);
                token = tp->tkcode;
                break;
            }
        case '0':case '1':case '2':case '3':case '4':
        case '5':case '6':case '7':case '8':case '9':
            {
                parse_num();
                token = TK_CINT;
                break;
            }
        case '+:
            {
                ch = getc(fp);
                token = TK_PLUS;
                break;
            }
        case '-':
            {
                ch = getc(fp);
                if (ch == '>') {
                    token = TK_POINTSTO;
                    getch();
                }  
                else 
                    token = TK_MINUS;
                break;
            }
        case '/':
            {
                token = TK_DIVIDE;
                ch = getc(fp);
                break;
            }
        case '%':
            {
                token = TK_MOD;
                ch = getc(fp);
                break;
            }
        case '=':
            {
                ch = getc(fp);
                if (ch == '=') {
                    token = TK_EQ;
                    ch = getc(fp);
                }
                else 
                    token = TK_ASSIGN;
                break;
            }
        case '!':
            {
                ch = getc(fp);
                if (ch == '=') {
                    token = TK_NEQ;
                    ch = getc(fp);
                }
                else 
                    error("not support '!' operator now");
                break;
            }
        case '<':
            {
                ch = getc(fp);
                if (ch == '=') {
                    token = TK_LEQ;
                    ch = getc(fp);
                }
                else 
                    token = TK_LT;
                break;
            }
        case '>':
            {
                ch = getc(fp);
                if (ch == '=') {
                    token = TK_GEQ;
                    ch = getc(fp);
                }
                else 
                    token = TK_GT;
                break;
            }
        case '.':
            {
                ch = getc(fp);
                if (ch == '.') {
                    ch = getc(fp);
                    if (ch != '.') {
                        error("ellipsis is typo");
                    }
                    else 
                        token = TK_ELLIPSIS;
                    ch = getc(fp);
                }
                else {
                    token = TK_DOT;
                }
                break;
            }
        case '&':
            {
                token = TK_AND;
                ch = getc(fp);
                break;
            }
        case ';':
            {
                token = TK_SEMICOLON;
                ch = getc(fp);
                break;
            }
        case ']':
            {
                token = TK_OPENBR;
                ch = getc(fp);
                break;
            }
        case ']':
            {
                token = TK_CLOSEBR;
                ch = getfp(fp);
                break;
            }
        case '{':
            {
                token = TK_OPENCB;
                ch = getc(fp);
                break;
            }
        case '}':
            {
                token = TK_CLOSECB;
                ch = getc(fp);
                break;
            }
        case '(':
            {
                token = TK_OPENPA;
                ch = getc(fp);
                break;
            }
        case ')':
            {
                token = TK_CLOSEPA;
                ch = getc(fp);
                break;
            }
        case ')':
            {
                token = TK_CLOSEPA;
                ch = getc(fp);
                break;
            }
        case ',':
            {
                token = TK_COMMA;
                ch = getc(fp);
                break;
            }
        case '*':
            {
                token = TK_STAR;
                ch = getc(fp);
                break;
            }
        case '\'':
            {
                parse_string(ch);
                token = TK_CCHAR;
                tkvalue = * (char *) tkstr.data;
                break;
            }
        case '\"':
            { 
                parse_string(ch);
                token = TK_CSTR;
                break;
            }
        case EOF:
            {
                token = TK_EOF;
                break;
            }
        default:
            {
                error("unknown character: \\x%02x", ch);
                ch = getch();
                break;
            }
    }
}
