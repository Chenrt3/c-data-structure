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

int Init(SQIST *l){
    l->list=(int*)malloc(MAXSIZE*sizeof(int));
    if(!l->list){
        return ERROR;
    }
    l->lenough=0;
    return OK;
}

int RsertSqist(SQIST *l,int lengh,int data){
    if(l->lenough==MAXSIZE){
        return ERROR;
    }
    else if (lengh>MAXSIZE||data<0)
    {
        return ERROR;
    }
    for(int i=lengh-1;i<=MAXSIZE-1;i++){
        l->list[i+1]=l->list[i];
    }
    l->list[lengh-1]=data;
    l->lenough++;
    return OK;
}

int DeleteSqist(SQIST *l,int lengh){
    if(l->lenough==0){
        return ERROR;
    }
    else if (lengh>MAXSIZE||lengh<0)
    {
        return ERROR;
    }
    for(int i=lengh-1;i<=l->lenough;i++){
        l->list[i]=l->list[i+1];
    }
    l->lenough--;
    return OK;
}

int ChangeSqist(SQIST *l,int lengh,int data){
    if (lengh>MAXSIZE||lengh<0)
    {
        return ERROR;
    }
    l->list[lengh-1]=data;
    return OK;
}

int OutPut(SQIST l){
    for(int i=0;i<l.lenough;i++){
        printf("number:%d,flag:%d,size:%d\n",l.list[i],l.list[i+1],l.lenough);
    }
    return OK;
}
