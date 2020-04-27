/*      my general mistakes that costed me a lot
          * check for overflows
          * check and mod and use int type variables where possible to avoid tles
          * while multiplying two variables whose value can exceed integer 
          limt make sure to typecase them
          * use scanf when you are not working with the best possible optimisation
          * return a value from a function that has a return type sometimes the 
          compiler may give the correct answer but there will be problem in the judge
          * be very cautious about uninitiaalised variables , infact never keep them
          or handle them properly*/
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long int
#define pp pair<int,int> 
#define ve vector
#define mod 1000000007
#define mn 100010
long long int MOD=mod;
long long int powe(ll a, ll b)
{
    long long int x=1,y=a; 
    while(b > 0)
    {   if(b%2 == 1) {   x=(x*y);x%=MOD; }
        y = (y*y);y%=MOD;b /= 2;
    }
    return x;
}
long long int InverseEuler(ll n)
{
    return powe(n,MOD-2);
}
//////////////************** code begins here***********************////////////////
int N=1e5;
void update(int pos,int bit[],int val)
{
      for(int i=pos;i<=N;i += i&(-i))
	  {
      	   bit[i]+=val;
	  }
}
int query(int b,int bit[])
{
	  	
  int sum = 0; 	
  for(; b > 0; b -= b&(-b))
    sum += bit[b];
    return sum;
}
int query(int a,int  b,int bit[]){

  return query(b,bit) - query(a-1,bit);
}
int bit[2*mn];
int a[2*mn];
int b[2*mn];
int main()
{
	int n;
	cin>>n;
	
		   map<int,int> m;
	   for(int i=1;i<=n;i++)
	   {
	   	   cin>>a[i];
	   	   m[a[i]]=i;
	   }
	   if(n==1 || n==2)
	   {
	   	  cout<<n<<endl;
	   	  return 0;
	   }

	   map<int,int>::iterator it;
	   int x=1;
	   for(it=m.begin();it!=m.end();it++)
	   {
	   	     int num=it->ff;
	   	     int idx=it->ss;
	   	    // cout<<"num idx "<<num<<" "<<idx<<endl;
	   	     b[x]=idx;
	   	   //  cout<<"b "<<idx<<" "<<x<<endl;
	   	     x++;
	   }
	    set<int> s;
	   for(int i=1;i<=n;i++)
	   {
	   	   
	   	    s.insert(b[i]);
	   }
	   int ans=2;
	   for(int i=1;i<=n-1;i++)
	   {
	   		  cout <<"----------------------"<<endl;
	   	      int sidx=*(s.begin());
	   	      int eidx=*(s.rbegin());
	   	      cout << "sidx = "<<sidx<<" eidx = "<<eidx<<endl;
	   	      int _ans = query(sidx,eidx,bit);
	   	      cout <<" _ans = "<<_ans <<endl;
	   	      ans=max(ans,2+query(sidx,eidx,bit));
	   	      cout <<"updated_ans = "<< ans <<endl;
	   	      int v=b[i];
	   	      cout <<"index to be updated in bit = "<<v<<endl;
	   	      update(v,bit,1);
	   	      cout << endl;
	   	      for(int i = 1;i<=8;i++) {
	   	      		cout <<bit[i]<<" ";
	   	      }
	   	      cout << endl;
	   	      cout << "index erased ="<<*s.lower_bound(v)<<endl;
	   	      s.erase(s.lower_bound(v));
	   }
	   cout<<ans<<endl;
	   return 0;
	   
	   
}

