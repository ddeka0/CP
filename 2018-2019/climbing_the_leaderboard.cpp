#include <bits/stdc++.h>
using namespace std;
template<typename T>
void LOG(T const& t) {
	std::cout << t;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
vector<int> scores;
vector<char> a_scores;
int main() {
	int n,m;
	cin >> n;
	for(int i = 0,x;i<n;i++) {
		cin >> x;
		scores.push_back(x);
	}
	cin >> m;
	for(int i = 0,x;i<m;i++) {
		cin >> x;
		a_scores.push_back(x);
	}
	std::vector<int> ranks;
	int prev_rank = 1;
	ranks.push_back(prev_rank);
	for(int i = 1;i<n;i++) {
		(scores[i] == scores[i-1])?ranks.push_back(prev_rank):ranks.push_back(++prev_rank);
	}
	cout <<"hi" << endl;
	cout << a_scores.size() << endl;
	for(int val:a_scores) {
		int pos = lower_bound(scores.begin(), scores.end(),val,[](int a, int b) { return a >= b;}) - scores.begin();
		cout << pos << endl;
		if(scores[pos - 1] == val) {
			cout << ranks[pos - 1] <<endl;
		}else if(scores[pos - 1] > val){
			cout << ranks[pos - 1] + 1 <<endl;
		}else if(scores[pos - 1] < val) {
			cout << ranks[pos - 1] + 1<<endl;
		}
	}
	return 0;
}