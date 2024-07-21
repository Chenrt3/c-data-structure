#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct BST_Node {
    DataType data;
    struct BST_Node *lchild, *rchild;
}BST_T, *BST_P;

BST_P Search_BST(BST_P root,DataType key){//查找键值
    if(!root)
    return NULL;
    if(key>root->data)
    return Search(root->rchild,key);
    else if(key<root->data)
    return Search(root->lchild,key);
    else
    return root;
}

void Insert_BST(BST_P *root,DataType key){//插入
    BST_P P=(BST_P)malloc(sizeof(struct BST_Node ));
    P->data=key;
    P->lchild=NULL;
    P->rchild=NULL;
    if(!root){
        *root=P;
        return;
    }
    if(Search_BST(root,key)!=NULL)
    return;
    BST_P *tnode=NULL,troot=root;
    while(troot){
        tnode=troot;
        troot=(key<troot->data)?troot->lchild:troot->rchild;
    }
    if(key<troot->data)
    (*tnode)->lchild=P;
    else
    (*tnode)->rchild=P;
    return P;
}

void Delete_BST(BST_P *root,DataType key){//删除
      if(root==NULL&&Search_BST(root,key)==NULL)
        return;
        BST_P *tnode=NULL,troot=root;
        
    if((*tnode)->lchild!=NULL||(*tnode)->rchild!=NULL){

    }
}

