#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int a[MAX];
map<int,int> l_map;
map<int,int> r_map;
int sum[MAX];
template<typename T> 
void LOG(T const& t) { 
	std::cout << t; 
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
int main() {
	string str;
	cin >> str;
	int n = str.length();
	for(int i = 0,x;i<n;i++) {
		a[i] = (str[i] == '0')?-1:1;
	}
	sum[0] = a[0];
	for(int i = 1;i<n;i++) {
		sum[i] = sum[i-1] + a[i];
	}
	for(int i = 0;i<n;i++) {
		if(l_map[sum[i]] == 0)
			l_map[sum[i]] = i;
	}
	for(int i = n-1;i>=0;i--) {
		if(r_map[sum[i]] == 0)
			r_map[sum[i]] = i;
	}
	int max_size = -1;
	for(int i = 0;i<n;i++) {
		//LOG("sum = ",sum[i]," l_map :",l_map[sum[i]]," r_map :",r_map[sum[i]],"\n");
		max_size = max(max_size,r_map[sum[i]] - l_map[sum[i]]);
	}
	cout << max_size << endl;
	return 0;
}