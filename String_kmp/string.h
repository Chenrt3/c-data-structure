#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1

typedef struct STRING{
        char *ch;
        int length;
}STRING;

STRING *Init(){
        STRING *S;
        S->ch=NULL;
        S->length=0;
}

int Index(STRING S,STRING T);
void get_next(STRING T,int *next);
int Index(STRING S,STRING T);
void get_nextval(STRING T, int *nextval);