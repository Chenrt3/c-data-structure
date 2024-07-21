#include"stack.h"

int main() {
	STACK S= Init();
	for (int i = 0; i < 10; i++) {
		Push(&S, i);/*实参是一个变量p，传递值给形参，则函数内部无论怎么做
都不会改变实参p的值,只有传地址才可以改变值.

实参是一个指针变量p，传递给形参，则函数内部无论怎么做
都不会改变实参p的指向,但可以通过地址改变指向的内容.*/
		printf("pushnmber:%d\n", Push(&S, i));
	}
		printf("Popnmber:%d\n", Pop(&S));
}