#include <bits/stdc++.h>
using namespace std;
struct A {
	int a;
	long int b;
	char x;
	int * c;
};
int main() {
    {
    	unique_ptr<A> obj(new A);
    	obj->a = 10;
    	obj->b = -1000;
    	obj->c = unique_ptr<int[]>(new int[100]);
    	cout << obj->b << endl;
    }
}
