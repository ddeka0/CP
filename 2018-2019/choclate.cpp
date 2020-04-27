#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[10] = {30,30,30,30,30,30,30,30,30,30};
	
	int Q = 5;
	int K = 7;
	int N = 10;



	int eaten = (Q-1)*K; // 28 done !

	int round = eaten/N;
	int idx = eaten%N; 

	std::vector<int> ans;
	 
	for(int i = 0;i<K;i++) {
		ans.push_back(  (idx + i)%N + 1);
	}
	for(int x:ans) {
		cout << x << endl;
	}

}