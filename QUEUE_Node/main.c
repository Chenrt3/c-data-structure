#include"queue.h"

int main() {
	LINKQUEUE *L = Init();
	for (int i = 0; i < 10; i++) {
		Enter_Queue(L, i);
	}
	OutPut(L);
	Delete_Queue(L);
	OutPut(L);
	return 0;
}