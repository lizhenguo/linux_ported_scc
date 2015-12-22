#include <stdio.h>

FILE *fp;
void filecopy(FILE *, FILE *);

int main(int argc, char *argv[])
{
    if (argc == 1) {
        fp = stdin;
        filecopy(fp, stdout);
    }
    else {
        int i = 1;
        while (--argc > 0) {
            if ((fp = fopen(argv[i], "rb")) != NULL) {
                filecopy(fp, stdout);
                fclose(fp);
            }
            i++;
        }
    }

    return 0;
}

void filecopy(FILE *ifp, FILE *ofp) {
    int ch;
    while ((ch = getc(ifp)) != EOF) {   // troublesome assignment and relational judgement
        putc(ch, ofp);
    }
}
