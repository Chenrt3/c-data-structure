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

int Index(STRING S,STRING T){//S2在S1的子串中寻找相等的子串
    int i=1,j=1;
    while(i<=S.length&&j<=T.length){//在长度范围内
        if(S.ch[i]==T.ch[i]){//如果相等就++比较下一位
            ++i;//++i：先自增，再返回自增之后的值，i++：先自增，再返回自增之前的值
            ++j;
        }
        i=i-j+2;//不相等S2的第一位与S1的下一位开始比较
        j=1;
    }
    if(j>T.length){//都不相等返回
        return i-T.length;
    }
    return OK;
}


void get_next(STRING T,int *next){
        int i=1,j=0;
        next[1]=0;
        while(j<T.length){
            if(j==0||T.ch[i]==T.ch[j]){//ch[i]表示后缀的单个字符，ch[j]表示前缀的单个字符
                ++i;
                ++j;
                next[i]=j;//若pi = pj， 则next[j+1] = next[j] + 1
            }
            else{
                j=next[j];//否则令j = next[j]，j值回溯，循环继续
            }

        }
}


int Index(STRING S,STRING T){//S2在S1的子串中寻找相等的子串
    int i=1,j=1;
    int next[255];
    get_next(T,next);
    while(i<=S.length&&j<=T.length){//在长度范围内
        if(S.ch[i]==T.ch[i]){//如果相等就++比较下一位
            ++i;//++i：先自增，再返回自增之后的值，i++：先自增，再返回自增之前的值
            ++j;
        }
        j=next[j];
    }
    if(j>T.length){//都不相等返回
        return i-T.length;
    }
    return OK;
}

void get_nextval(STRING T, int *nextval){
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < T.length){
		if(j==0 || T.ch[i]==T.ch[j]){	//ch[i]表示后缀的单个字符，ch[j]表示前缀的单个字符
			++i; ++j;

			if(T.ch[i] != T.ch[j]){	//若当前字符与前缀字符不同
				nextval[i] = j;	//则当前的j为nextval在i位置的值
			}else{
				//如果与前缀字符相同
				//则将前缀字符的nextval值给nextval在i位置上的值
				nextval[i] = nextval[j];
			}
		}else{
			j = nextval[j];	//否则令j = next[j]，j值回溯，循环继续
		}
	}
}