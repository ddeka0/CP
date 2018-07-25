#include <bits/stdc++.h>
using namespace std;
template<typename T>
void LOG(T const& t) {std::cout <<t<<endl;}
template<typename First, typename ... Rest>
void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
long long modpow(long long a,long long x,long long M) {
	long long res = 1;
	while(x) {if(x&1) res = (res*a)%M; a = (a*a)%M; x/=2;}
	return res;
}
#define show(a) std::cout << #a << ": " << (a) << std::endl
long long f[100009];
long long rf[100009];
void inv_factorials(long long M) {
	f[0] = 1;
	long long m = 100000;
	for(int i = 1;i<=m;i++) {f[i] = (f[i - 1]*i)%M;}
	rf[m] = modpow(f[m],M-2,M);
	for(int i = m - 1;i>=0;i--) {rf[i] = (rf[i+1]*(i+1))%M;}
}
long long  C(int _n,int _r,long long M) {return (_r <0 || _r > _n)?0 : f[_n]*rf[_r]%M*rf[_n - _r]%M; }
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}

map<string,int> rating;
map<string,int> freq;
std::vector<string> v;
bool comp(const string &a,const string &b) {
	if(freq[a] < freq[b]) return true;
	if(freq[a] > freq[b]) return false;
	return (rating[a] < rating[b])?true:false;
}
bool comp2(const string &a,const string &b) {
	return (rating[a] < rating[b])?true:false;
}
void solve() {
	int T,N,K;
	long long V;
	cin >> T;
	for(int q = 1;q <= T;q++) {
		cout <<"Case #"<<q<<": ";
		cin >> N >> K >> V;
		string s;
		for(int i = 0;i<N;i++) {
			cin >> s;
			rating[s] = i; freq[s] = 0; v.push_back(s);
		}
		int M = (V - 1)%N;
		for(int i = 1;i<=M;i++) {
			for(int j = 0;j<K;j++) freq[v[j]]++;
			sort(v.begin(), v.end(),comp);
		}
		sort(v.begin(),v.begin() + K,comp2);
		for(int k =0;k<K;k++) 
			cout << v[k] <<" ";
		cout << endl;
		rating.clear(); v.clear();freq.clear();
	}
}