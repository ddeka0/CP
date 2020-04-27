#include <bits/stdc++.h>
using namespace std;
vector<int> A1,A2,A3,A4;
map<int,int> positions;
map<int, int> has;
bool compare(int a,int b) {
	return (positions[a] < positions[b]);
}
int main() {
	int T,N,M;
	cin >> T;
	for(int q = 1;q<=T;q++) {
		cin >> M >> N;
		for(int i = 0,x;i<M;i++) {
			cin >> x;
			A1.push_back(x);
		}
		for(int i = 0,x;i<N;i++) {
			cin >> x;
			positions[x] = i;
			has[x] = 1;
			A2.push_back(x);
		}
		for(int i = 0;i<M;i++) 
			(has[A1[i]]) ? A3.push_back(A1[i]):A4.push_back(A1[i]);
		
		sort(A3.begin(), A3.end(),compare);
		sort(A4.begin(), A4.end());
		for(int e:A3) cout << e <<" ";
		for(int e:A4) cout << e <<" ";
		cout << endl;
		A1.clear();A2.clear();A3.clear();A4.clear();
		positions.clear();
		has.clear();
	}
	return 0;
}



