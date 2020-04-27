#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;	
	cin >> str;
	vector<pair<int,int>> RL;
	vector<pair<int,int>> RR;
	vector<pair<int,int>> LL;
	bool R_found = false;
	pair<int,int> span;
	for(int i = 0;i<str.length();i++) {
		if(str[i] == 'R' && !R_found) {
			R_found = true;
			span.first = i;
		}else if(str[i] == 'R' && R_found) {
			RR.push_back(make_pair(span.first,i));
			span.first = i;
		}else if(str[i] == 'L' && R_found) {
			R_found = false;
			span.second = i;
			RL.push_back(span);
		}
	}
	bool L_found = false;
	for(int i = str.length() - 1;i >= 0;i--) {
		if(str[i] == 'L' && !L_found) {
			L_found = true;
			span.second = i;
		}else if(str[i] == 'L' && L_found) {
			LL.push_back(make_pair(i,span.second));
			span.second = i;
		}else if(str[i] == 'R') {
			L_found = false;
		}
	}
	for(auto e:RR) {
		for(int i = e.first;i<=e.second;i++) {
			str[i] = 'R';
		}
	}
	for(auto e: LL) {
		for(int i = e.first;i<=e.second;i++) {
			str[i] = 'L';
		}
	}
	for(auto e:RL) {
		for(int i = e.first , j = e.second ; i<=j ; i++,j--) {
			if(i != j) {
				str[i] = 'R';
				str[j] = 'L';
			}
		}
	}
	
	for(int i = 0;i<str.length();i++) {
		if(str[i] == '.') continue;
		if(str[i] == 'R') break;
		if(str[i] == 'L') {
			for(int j = i;j>=0;j--) {
				str[j] = 'L';
			}
			break;
		}
	}
	for(int i = str.length() - 1;i>=0;i--) {
		if(str[i] == '.') continue;
		if(str[i] == 'L') break;
		if(str[i] == 'R') {
			for(int j = i;j<str.length();j++) {
				str[j] = 'R';
			}
			break;
		}
	}
	for(int i = 0;i<str.length();i++) {
		cout << str[i];
	}
	cout << endl;
	return 0;

}


















