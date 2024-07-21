#include"tree.h"
int main(){
    CTREE T;//创造结构体对象时尽量直接创建，CTREE *T创建时容易产生指针未初始化
    int size;
    /*char ch[]="abcdefghij";
    int loc[10];
    for(int i=0;i<10;i++){
        loc[i]=i;
    }
    Creat_Box(T,ch,loc);
    for(int i=0;i<10;i++){
    printf("NUMBER:%C\n",T->NODES[i].data);
    }*/
    printf("输入树的尺寸：");
    scanf("%d",&size);
    CreateTree(&T,size);
    OutPut(&T);
}