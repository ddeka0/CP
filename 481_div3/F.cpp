#include<bits/stdc++.h>
using namespace std;
int a[200009];
int b[200009];
int c[200009];
int main() {
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	int u,v;
	for(int i=0;i<m;i++) {
		cin >> u >> v;
		if(a[v-1] < a[u-1]) c[u-1]++;
		else if(a[v-1] > a[u-1]) c[v-1]++;
	}
	sort(b,b+n);
	for(int i = 0;i<n;i++) {
		int idx = lower_bound(b,b+n,a[i]) - b;
		cout << idx - c[i] << " ";
	}
	cout << endl;
}