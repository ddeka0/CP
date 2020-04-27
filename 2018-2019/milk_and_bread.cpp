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
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int my,milk,brd;
	cin >> my >> milk >> brd;
	if(milk <= my && brd <= my) {
		int ans = max (  abs( my - brd ) , abs( my - milk )  );
		cout << 2*ans << endl;
	}else if(milk >= my && brd >= my) {
		int ans = max (  abs( my - brd ) , abs( my - milk )  );
		cout << 2*ans << endl;
	}else {
		int ans = abs(milk - my) + abs(brd - my);
		cout << 2*ans << endl;
	}

	return 0;
}