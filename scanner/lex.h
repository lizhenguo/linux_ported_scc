/* token code */

enum TokenCode {
    /* operators and delimiters */
    TK_PLUS,       // +
    TK_MINUS,      // -
    TK_STAR,       // *
    TK_DIVIDE,     // /
    TK_MOD,        // % mod
    TK_EQ,         // ==
    TK_NEQ,        // !=
    TK_LT,         // <
    TK_LEQ,        // <=
    TK_GT,         // >
    TK_GEQ,        // >=
    TK_ASSIGN,     // = (assign)
    TK_POINTSTO,   // ->
    TK_DOT,        // .
    TK_AND,        // & (get address)
    TK_OPENPA,     // ( (parenthesis)
    TK_CLOSEPA,    // )
    TK_OPENBR,     // [ (bracket)
    TK_CLOASEBR,   // ]
    TK_OPENCB,     // { (curly brace)
    TK_CLOSECB,    // }
    TK_SEMICOLON,  // ;
    TK_COMMA,      // ,
    TK_ELLIPSIS,   // ...
    TK_EOF,        // end of file

    /* constant */
    TK_CINT,       // const integer
    TK_CCHAR,      // const chararcter
    TK_CSTR,       // const string

    /* keyword */
    KW_CHAR,       // char
    KW_SHORT,      // short
    KW_INT,        // int
    KW_VOID,       // void
    KW_STRUCT,     // struct
    KW_IF,         // if
    KW_ELSE,       // else
    KW_FOR,        // for
    KW_CONTINUE,   // continue
    KW_BREAK,      // break
    KW_RETURN,     // return
    KW_SIZEOF,     // sizeof

    KW_ALIGN,      // __align
    KW_CDECL,      // __cdecl
    KW_STDCALL,    // __stdcall

    /* identifier */
    TK_IDENT
};

extern FILE *fp;

