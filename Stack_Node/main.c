#include"stack.h"

int main(){
    stack S=Init();
    for(int i=0;i<10;i++){
      Push(S,i);  
    }
    Output(S);
    Pop(S);
    return 0;
}