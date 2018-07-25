#include <bits/stdc++.h>

using namespace std;
int n, k, x;
long long modd = 1e9+7;
vector<vector<int> > dp;
	
int fun(int x, int y){
	if(x >= n)return 1;

	if(x == n-1){
	if(y == 1)return 0;
	else return 1;
	}
	if(dp[x][y] != -1)return dp[x][y];

	int ans = 1;

	if(y == 1){
		if(x == n-2)ans = 1;
		else
		ans = (((k-1)*fun(x+2,1))%modd + ((k-2)*fun(x+2,0))%modd)%modd;

	}
	else{
		if(x == n-2)return (k-2);	
	 ans =    (((k-1) * fun(x+1,1))%modd + ( (k-2)*fun(x+1,0))%modd)%modd;
	}

	dp[x][y] = ans;
	cout << "x is " << x ;
	cout <<  " y is "<<y;
	cout << " ans is "<<ans <<endl;
	return ans;



}





int main(){
	cin >> n >> k >> x;
	dp.resize(n);
	for(int i = 0; i < n; i++)dp[i].resize(2);

	for(int i = 0; i < n; i++)for(int j = 0; j < 2; j++)dp[i][j] = -1;


	cout << fun(0,1);



}