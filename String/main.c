#include"string.h"

int main() {
	STRING *S= Init();
	STRING *P= Init();
	STRING *Sub= Init();
	char s[] = "abcdefg";
	char t[] = "cbcdefg";
	STRING T = { t,8 };
	StrAssign(S, s);
	printf("Input:%c\n", S->ch[0]);
	Strcopy(S,T);
	printf("Input:%c\n", S->ch[0]);
	printf("Compare:%d\n", StrCompare(S, T));
	Concat(P, S, T);
	printf("Input:%c\n", P->ch[0]);
	Substring(Sub, S, 0, 3);
	printf("Sub:%c\n", Sub->ch[0]);
	printf("Index:%d\n", Index(S,T));
	return 0;
}