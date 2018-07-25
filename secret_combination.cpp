#include<bits/stdc++.h>
using namespace std;
int main() {
	string num;
	cin >> num;
	int n = num.length();
	string min_num = num;
	for(int i = 0;i<n;i++) {
		string nxt_string = num.substr(0,n-1);
		nxt_string.insert(0,1,num[n-1]);
		//cout << nxt_string << endl;
		min_num = min(min_num,nxt_string);
		num = nxt_string;
	}
	int diff  = 10 - ( min_num[0] - '0');
	min_num[0] = '0';
	for(int i = 1;i<n;i++) {
		min_num[i] =  '0' +(min_num[i] + diff)%10;
	}
	cout << min_num << endl;
	return 0;	
}