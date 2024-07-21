#include"list.h"

int main() {
	List L;
	L = Init();
	for (int i = 0; i < 10; i++) {
		Insert(L, i, i);
	}
	OutPut(L);
	Delete(L, 2);
	OutPut(L);
	return 0;
}