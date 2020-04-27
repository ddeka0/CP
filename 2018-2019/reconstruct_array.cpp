#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
int a[(1<<18) + 10];
int sets[(1<<18) + 10];
multiset<int> heap;
vector<int> ans;
int N,M;
int main() {
	cin >> N;
	int M = 1 << N;
	for(int i = 0;i<M;i++) {
		cin >> x;
		a[i] = x;
		heap.insert(x);
	}
	sort(a,a+N);
	ans.push_back(a[1]);
	ans.push_back(a[2]);
	sets[1] = a[1];
	sets[2] = a[2];
	int cnt = 2;
	sets[3] = a[1] + a[2];
	int _back = 3;
	int _front = 3;
	while(cnt < N) {
		if(heap.size() == 1) {
			ans.push_back(*heap.begin());
			break;
		}
		for(int i = _front;i >=_back;i--) heap.erase(heap.lower_bound(sets[i]));
		_back = _front;
		int new_elem = *heap.begin();
		ans.push_back(new_elem);
		heap.erase(heap.begin());
		sets[++_front] = new_elem;
		for(int i = 1;i<=_back;i++) sets[++_front] = sets[i] + new_elem;
		_back+=2;
		cnt++;
	}
	for(int e:ans) cout << e <<" ";
	cout << endl;
	return 0;
}