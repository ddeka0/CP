#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[6] = {0,3,3,9,9,20};
	for(int i = 0;i<=20;i++)
		cout <<i<<" upper : "<<upper_bound(a,a+5,i) - a<<"||  lower : "<<lower_bound(a,a+5,i) - a << endl;
}