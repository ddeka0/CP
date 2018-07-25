#include <bits/stdc++.h>
using namespace std;
int f(int p,float q) {
	double temp = 3;
	for(int i = 0;i < p;i++)
		temp *= 6*q;
	return temp*(1 - (p%3));
}
int main() {
    char c = 'A';
    void * p = &c;
    printf("%d\n",sizeof *(true?(NULL *)2:(long int *)1));
}
