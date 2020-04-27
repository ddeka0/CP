#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 7;

int n;
string s[N];
char buf[N];
int cnt[N];

int getBalance(string &s){
	int bal = 0;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '(')
			++bal;
		else
			--bal;
		
		if(bal < 0)
			return -1;
	}
	
	return bal;
}

string rev(string &s){
	string revs = s;
	reverse(revs.begin(), revs.end());
	for(int i = 0; i < revs.size(); ++i)
		if(revs[i] == '(')
			revs[i] = ')';
		else
			revs[i] = '(';
		
	return revs;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", buf);
		s[i] = buf;
	}

	for(int i = 0; i < n; ++i){
		int bal = getBalance(s[i]);
		if(bal != -1)
			++cnt[bal];
	}
	
	long long res = 0;	
	for(int i = 0; i < n; ++i){
		s[i] = rev(s[i]);
		int bal = getBalance(s[i]);
		if(bal != -1)
			res += cnt[bal];
	}
	
	printf("%I64d\n", res);
	return 0;
}