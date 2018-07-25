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
int T;
double EPS = 1e-5;
long long int h[100009];
long long int N,k,l;
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> N >> k >> l;
	long long int M = N*k;

	long long int lb,ll,total,upper,upper_bound,left,i=0,no_upper; 

	for(i = 0;i<M;i++) cin >> h[i];
	sort(h,h+M);

	//lb = upper_bound(h,h+M, h[i]+l);

	for (i = 1; i < M; ++i)
	{
		if(h[i]-h[0]>l)
			break;
		/* code */
	}
	lb=i-1;
	if(lb<N-1)
		{
			cout<<0<<endl;
			return 0;
		}
	
	upper = (M-lb-1);

	if(k!=1)
	{
	no_upper= upper/(k-1);

	left = upper%(k-1);
    }
    else
    {
    	no_upper= 0;

		left = 0;
    }
	ll = lb - no_upper;
	//LOG(i,lb,upper,no_upper,left,ll,"\n");
	total =0;
	for (i = lb; i >ll ; --i)
	{
		total +=h[i];
		/* code */
	}
	//LOG(i,lb,upper,no_upper,left,total,ll,"\n");
    ll++;
	if(left)
	{
		ll = ll -(k-left);
		total +=h[ll]; 

	}	
	//LOG(i,lb,upper,no_upper,left,total, ll,"\n");
	for (i = ll-k; i >=0 ; i=i-k)
	{
		total +=h[i];
		/* code */
	}

	cout<<total<<endl;
	


	return 0;
}


