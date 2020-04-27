#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int final_loc;
double solve(int pos,int loc) {
	if(pos == (int)s1.length() ) {
		if(loc == final_loc) return 1.0;
		else return 0;
	}
	double res = 0;
	if(s2[pos] == '?') {
		res += 0.5*solve(pos+1,loc+1);
		res += 0.5*solve(pos+1,loc-1);	
	}else {
		res = solve(pos + 1,  (s2[pos] == '+')? (loc + 1) : (loc - 1) );
	}
	return res;
}
int main() {
	double ans = 1.0;
	cin >> s1;
	cin >> s2;
	if(s1 == s2) {
		printf("%.12lf\n",ans);
	}else if(s2.find("?") == string::npos) {
		int cnt = 0;
		for(int i=0;i<s1.length();i++) {
			if(s1[i] == '+') cnt++;
			if(s2[i] == '+') cnt--;
		}
		if(cnt == 0) printf("%.12lf\n",ans);
		else printf("%.12lf\n",0.0);
		return 0;
	}else {
		for(int i = 0;i<(int)s1.length();i++) {
			(s1[i] == '+')?final_loc++ : final_loc--;
		}
		double val = solve(0,0);
		printf("%.12lf\n",val);
	}
	return 0;
}