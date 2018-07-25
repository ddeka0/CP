#include<bits/stdc++.h>
using namespace std;

//int a[1000][1000],b[1000],dp[];

int n,m;

int solve(int j, int len,int c[],int dp[]){
	
	if(j>=len)
		return 0;
	if(j==len-1)
		return c[j];
	if(dp[j]!=-1)
		return dp[j];
	
	dp[j]=max(c[j] + solve(j+2, len, c, dp ), solve(j+1 , len, c,dp));
	//cout<<dp[j]<<" j "<<j<<endl;
	return dp[j];
}

int main() {

	cin>>n>>m;
	while(n && m){

		// int** a = (int**)malloc((n+1) * (m+1) * sizeof(int));
		// int b=(int)malloc((n+1)*sizeof(int));
		// int dp=(int)malloc(max(n+1,m+1)*sizeof(int)); 
		int k=max(n,m);
		int a[n+1][m+1], b[n+1], dp[k+1];


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			
			cin>>a[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		memset(dp,-1,sizeof(int)*m);
		b[i]=solve(0,m,a[i],dp);
		//cout<<b[i]<<endl;
	}
	memset(dp,-1,sizeof(int)*n);
	//cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
	cout<<solve(0,n,b,dp)<<endl;

	cin>>n>>m;
   }

	return 0;

}