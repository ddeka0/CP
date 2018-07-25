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
int n,m;
long long int K;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);