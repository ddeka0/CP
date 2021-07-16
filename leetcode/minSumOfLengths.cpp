#define DEBUG1
#ifdef DEBUG
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;
#else
#define trace(...) (void(0))
#define debug(...) (void(0))
#define debugc(...) (void(0))

#endif

const int N = 100000;
int dp1[N+2];
int dp2[N+2];
int Sum[N+2];
const int INF = 1000000000;
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
		int n = arr.size();
		Sum[0] = 0;
		for(int i = 1;i<=n;i++) Sum[i] = Sum[i-1] + arr[i-1];
		
		std::map<int,int> Map;
		
		Map[0] = 0;
		dp1[0] = INF;
		
		for(int i = 1;i<=n;i++) {
			dp1[i] = INF;
			
			if(Sum[i] < target) {
				Map[Sum[i]] = i;
				continue;
			}
			int thisLen = INF;
			auto found = Map.find(Sum[i] - target);
			
			if(found != Map.end()) {
				thisLen = i - (*found).second;	
			}

			dp1[i] = std::min(thisLen,dp1[i-1]);
			Map[Sum[i]] = i;
		}
        
        debugc(dp1);
		
        Map.clear();
		Map[0] = n + 1;
		dp2[n+1] = INF;
		
		for(int i = n;i>=1;i--) {
			dp2[i] = INF;
			int S = Sum[n] - Sum[i-1];
			if(S < target) {
				Map[S] = i;
				continue;
			}
			int thisLen = INF;
			auto found = Map.find(S - target);
			if(found != Map.end()) {
				thisLen = (*found).second - i;
				
			}
			
			dp2[i] = std::min(thisLen,dp2[i+1]);
			Map[S] = i;
		}
        
        debugc(dp2);
        
        long long ans = INF;
		
		for(int i = 1;i<=n - 1;i++) {
			ans = std::min(ans,(long long)dp1[i] + dp2[i+1]);
		}

		return ans < INF ? (int)(ans) : -1;
    }
};