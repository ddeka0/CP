#include<bits/stdc++.h>
using namespace std;
int main() {
	// string str;
	// cin >> str;
	vector<int> nums;
	
	for(int i = 1;i<10;i++) {
		nums.push_back(i);
	}

	do {
		for(int e:nums) {
			cout << e <<" ";
		}
		cout << endl;
	}while(next_permutation(nums.begin(),nums.end()));

	cout << endl;
	return 0;
}