#include <bits/stdc++.h>
using namespace std;
int N = 10;
int M = 20;
void func(vector<vector<int>> &a) {
	a[2][4] = 5;
	a[5][7] = 19;
}
void func2(int *a) {
	for(int i = 0;i<N;i++) {
		for(int j = 0;j<M;j++) {
			*((a+i*N) + M) = 4;
		}
	}
}
int main() {
	vector<vector<int>> table(N,vector<int>(M,0));
	
	int a[N][M] = {};
	
	func2((int *)a);

	cout << a[1][3] << endl;


	func(table);
	cout << table[2][4] << endl;
	cout << table[5][7] << endl;
}