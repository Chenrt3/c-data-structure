#include"tree.h"

int main() {
	BiTree B;//不定义指针可以防止指针初始化问题
	Create(&B);//传入地址
	first_print(B);
	printf("\n");
	mid_print(B);
	printf("\n");
	fina_print(B);
	printf("\n");
	return 0;
}