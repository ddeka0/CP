#include<bits/stdc++.h>
using namespace std;
string a;
string b;
int n;
string s;
#define ll long long int 
ll dp[20][20*9+2][2];
ll solve(int pos,int sum,int tight)
{
	 if(pos==n)
	 {
	 	return (sum==0);

	 }
	 if(sum<0)
	 	return 0;
	 ll res=0;
	 if(tight==0)
	 {
	 	 for(int i=0;i<=9;i++)
	 	 {
	 	 	res+=solve(pos+1,sum-i,0);
	 	 }
	 }
	 if(tight==1)
	 {
	 	 for(int i=0;i<=s[pos]-'0';i++)
	 	 {
	 	 	 int nt=0;
	 	 	 if(i==s[pos]-'0')
	 	 	 	nt=1;
	 	 	 res+=solve(pos+1,sum-i,nt);
	 	 }
	 }
	 return res;
}
int main()
{
	cin>>s;
	n=s.length();
	int T;
	cin>>T;
    cout<<solve(0,T,1)<<endl;
}