#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR -1

typedef struct STRING {
	char *ch;//按照串长分配地址
	int length;//串的长度
}STRING;

STRING *Init() {
	STRING *S = (STRING *)malloc(sizeof(STRING));
	S->ch = NULL;
	S->length = 0;
	return S;
}

int StrAssign(STRING *S, char *s) {//串的赋值
	S->ch= (char *)malloc(sizeof(char));//给字符串开辟地址而不是结构体
	for (int i = 0; s[i] != '\0'; i++) {
		S->ch[i] = s[i];
		S->length++;
	}
	return OK;
}

int Strcopy(STRING *S, STRING T) {//T复制给S
	for (int i = 0; T.ch[i] != '\0'; i++) {
		S->ch[i] = T.ch[i];
		T.length++;
	}
	return OK;
}

int StrCompare(STRING *S, STRING T) {//两串比较
	for (int i = 0; i < S->length&&i < T.length; i++) {
		if (S->ch[i] != T.ch[i])
			return S->ch[i] - T.ch[i];
	}
	return S->length - T.length;
}

int Concat(STRING *P, STRING *S, STRING T) {//串的连接,S和T连接存放到P中
	P->ch = (char *)malloc(sizeof(char)*(S->length + T.length)); //给字符串开辟地址而不是结构体
	for (int i = 0; i < S->length; i++) {
		P->ch[i] = S->ch[i];
	}
	for (int i = S->length; i < S->length + T.length; i++) {
		P->ch[i] = T.ch[i];
	}
	return OK;
}

int Substring(STRING *Sub, STRING *S, int pos, int len) {//求子串，将s从第pos位起len个长度的子串用sub返回
	Sub->ch = (char *)malloc(sizeof(char)*len);
	for (int i = pos; i < len; i++) {
		Sub->ch[i] = S->ch[i];
	}
	Sub->length = len;
	return OK;
}


int Index(STRING *S, STRING T) {//索引操作，在S中寻找子串和T相等
	STRING *Sub = Init();
	int pos = 0; int i = 0;
	int len = T.length;
	while (pos + len <= S->length) {//子串不能超过S的长度
		Substring(Sub, S, pos, len);//找子串
		if (StrCompare(Sub, T))//子串相等则再寻找
			i++;
	}
			return i;//不相等就返回i的值
}