#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t<<endl;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
int L[100009];
int R[100009];
int a[100009];
int n,m;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> n>>m;
	for(int i = 0;i<n;i++) {
		cin >> a[i];
	}
	L[0] = 1;
	R[n - 1] = 1;
	for(int i = 1,j = n-2;i<n;i++,j--) {
		L[i] = (a[i] <= a[i-1])?L[i-1] + 1:1;
		R[j] = (a[j] <= a[j+1])?R[j+1] + 1:1;
	}
/*	for(int i = 0;i<n;i++) {
		cout <<R[i]<<" ";
	}
	LOG("");
	for(int i = 0;i<n;i++) {
		cout <<L[i]<<" ";
	}
	LOG("");*/
	for(int i = 0,x,y;i<m;i++) {
		cin >> x >> y;
		x--,y--;
		int rr = x + R[x] - 1;
		int ll = y - L[y] + 1;
		if(rr >= ll) {
			cout << "Yes"<<endl;
		}else {
			cout <<"No"<<endl;
		}
	}
	return 0;
}