#include"queue.h"

int main(){
    QUEUE Q=Init();
    for(int i=0;i<10;i++){
        Enter_Queue(&Q,i);
    }
    OutPut(Q);
    Delete_Queue(&Q);
    OutPut(Q);
    return 0;
}