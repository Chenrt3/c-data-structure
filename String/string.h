#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR -1

typedef struct STRING{
        char *ch;//按照串长分配地址
        int length;//串的长度
}STRING;
STRING *Init();
int StrAssign(STRING *S, char *s);
int Strcopy(STRING *S, STRING T);
int StrCompare(STRING *S,STRING T);
int Concat(STRING *P,STRING *S,STRING T);
STRING * Substring(STRING *Sub,STRING *S,int pos,int len);
int Index(STRING *S,STRING T);