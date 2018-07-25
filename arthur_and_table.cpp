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
long long C(int _n,int _r,long long M) {return (_r <0 || _r > _n)?0 : f[_n]*rf[_r]%M*rf[_n - _r]%M; }
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}

#define ff      first
#define ss      second
int n;
int total_energy;
int len[100009];
int energy[100009];
int freq[100009];
vector<pair<int,int>> v;
void solve() {
    cin >> n;
    for(int i = 1;i<=n;i++) {
        cin >> len[i];
    }
    for(int i = 1;i<=n;i++) {
        cin >> energy[i];
        total_energy += energy[i];
        v.push_back(make_pair(len[i],energy[i]));
    }
    sort(v.begin(),v.end());
    int ans = 1e9;
    for(int i = 0; i< n;i++) {
        int how_many_max = 0;
        int scan_start_indx = i;
        int total_energy_of_majority_legs = 0;
        while(v[i].ff == v[i+1].ff) {
            how_many_max++;
            total_energy_of_majority_legs += v[i].ss;
            i++;
        }
        how_many_max++;
        total_energy_of_majority_legs += v[i].ss;
        show(i);


        int energy_value = 200;
        int total_smaller_legs_needed = how_many_max - 1;
        int total_energy_of_smaller_legs = 0;
        while(total_smaller_legs_needed > 0 && energy_value > 0) {
            if(freq[energy_value] > 0) {
                total_energy_of_smaller_legs = total_energy_of_smaller_legs + energy_value * min(total_smaller_legs_needed , freq[energy_value]);
                total_smaller_legs_needed = min(0,total_smaller_legs_needed - freq[energy_value]);
            }
            energy_value--;
        }
        for(int j = scan_start_indx;j<how_many_max && j < n;j++) {
            freq[v[j].ss]++;
        }
        ans = min(ans,total_energy - total_energy_of_majority_legs - total_energy_of_smaller_legs);
    }
    cout << ans << endl;
}
