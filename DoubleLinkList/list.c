#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1

typedef struct NODE{
    int data;
    struct NODE *next;//后继节点
    struct NODE *porior;//前驱节点
}NODE;
typedef struct NODE *LIST;

LIST Init(){
    LIST list=(LIST)malloc(sizeof(NODE));
    if(list==NULL){
       printf("初始化失败\n");
    }
    list->next=NULL;
    list->porior=NULL;
    list->data=-1;
    return list;
}

int Insert(LIST L,int data,int poss){
    NODE *head=L;
    for(int i=0;i<poss;i++){
        head=head->next;
    }
    NODE *new=(NODE *)malloc(sizeof(NODE));
    new->data=data;
    new->porior=head;
    new->next=head->next;
    head->next=new;
    head->next->porior=new;
    return OK;
}

int Delete(LIST L,int poss){
    NODE *head=L;
     for(int i=0;i<poss;i++){
        head=head->next;
    }
    NODE *delete=(NODE *)malloc(sizeof(NODE));
    delete=head->next;
    head->next=delete->next;
    delete->next->porior=head;
    free(delete);
    return OK;
}

int OutPut (LIST L){
    NODE *head=L->next;
      while(head!=NULL){
         printf("number:%d\n",head->data);
        head=head->next;
    }
}