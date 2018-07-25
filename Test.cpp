#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(NULL));
	set<int> s;
	s.insert(rand()%100);
	s.insert(rand()%100);
	s.insert(rand()%100);
	s.insert(rand()%100);
	s.insert(rand()%100);
	s.insert(rand()%100);
	s.insert(rand()%100);
	s.insert(rand()%100);
	s.insert(rand()%100);
	s.insert(rand()%100);
	s.insert(rand()%100);
	s.insert(rand()%100);

	for(auto e:s) {
		cout << e <<" ";
	}
	cout << endl;
	int n;
	while(cin >> n) {
		cout << distance(s.begin(), s.find(n)) << endl;
	}

	// cout << idx << endl;
}
