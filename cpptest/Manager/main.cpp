#include"manage.h"
int main() {
	BOSS B;
	Manager M;
	vector<BOSS>vec;
	Menu();
	B.Select(B, vec);
	B.Select(M, vec);
	B.Outfile(vec);
	return 0;
}