#include"sqist.h"

int main(){
SQIST l;
Init(&l);
for(int i=0;i<10;i++){
    RsertSqist(&l,i+1,i);
}
OutPut(l);
DeleteSqist(&l,4);
OutPut(l);
ChangeSqist(&l,2,13);
OutPut(l);
return 0;
}