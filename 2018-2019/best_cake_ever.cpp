#include <bits/stdc++.h>
using namespace std;
/*template code starts*/
template<typename T>
void LOG(T const& t) {
	std::cout << t;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
/*template code ends*/
int T;
double EPS = 1e-5;
typedef unsigned long long int ULL;
ULL k_count,n_max;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int q = 1;q<= T;q++) {
	    cin >> k_count >> n_max;
	    int high  = 64 - __builtin_clzll(n_max);
	    if(k_count == 1) {
	        cout << n_max << endl;
	        return 0;
	    }
	    if(n_max == 1) {
	    	for(int i = 0;i<k_count;i++) {
	    		cout <<"1"<<" ";
	    	}
	    	cout << endl;
	    	return 0;
	    }else if(n_max == 3 && k_count%2 == 1) {
	    	if(k_count >= 3) {
	    		for(int i = 0;i<k_count - 3;i++) {
		    		cout<<"1" <<" ";
		    	}
	    		cout << 3 <<" "<<1<<" "<<1<<endl;
	    		return 0;
	    	}
	    }else if(n_max == 2 && k_count%2 == 1) {
	    	if(k_count >= 3) {
	    		for(int i = 0;i<k_count - 3;i++) {
		    		cout<<"1" <<" ";
		    	}
	    		cout << 2 <<" "<<1<<" "<<1<<endl;
	    		return 0;
	    	}
	    }


	    ULL ans = (1LL<<high) - 1LL;
	    high  = 64 - __builtin_clzll(ans) - 1;
	    ULL x = 1LL<<high;
	    ULL y = (~x)&ans;
		if(k_count == 2) {
	    	cout<<x<<" "<<y<<endl;
	    	return 0;
	    }else {
	    	if(k_count%2 == 0) {
		    	for(int i = 0;i<k_count - 2;i++) {
		    		cout<<"1" <<" ";
		    	}
		    	cout<<x<<" "<<y<<endl;
		    	return 0;
	    	}else {
	    		for(int i = 0;i<k_count - 3;i++) {
		    		cout<<"1" <<" ";
		    	}
		    	cout <<x << " "<< (y & (~1)) <<" 1" <<endl;
	    	}
	    }
    }
    return 0;
}