#include "b.hpp"
#define AA
#ifdef AA
	int a[100];
#endif	



void func() {
	for(int i = 0;i<100;i++) {
		a[i] = i;
	}
	cout << a[50] << endl;
}