#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
#define OK 1
#define ERROR -1

typedef struct sqist
{
    int *list ;/* 数组 */
    int lenough;
}SQIST;

int Init(SQIST *l);
int RsertSqist(SQIST *l,int lengh,int data);
int DeleteSqist(SQIST *l,int lengh);
int ChangeSqist(SQIST *l,int lengh,int data);
int OutPut(SQIST l);