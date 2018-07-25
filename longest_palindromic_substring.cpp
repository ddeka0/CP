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

class Solution {
public:
    string longestPalindrome(string s) {
    	int n = s.length();
    	string T = "";
    	if(n == 0) T += "^$";
    	else {
    		T += "^";
    		for(int i = 0;i<s.length();i++) {
    			T += "#" + s.substr(i,1);
    		}
    		T += "#$";
    	}
    	int *P = new int[T.length()];
    	int C = 0,R = 0;
    	for(int i = 1;i<T.length() - 1;i++) {
    		int mirror = C - (i - C);
    		P[i] = (i < R)?min(R-i , P[mirror]):0;
    		while(  T[i + 1 + P[i]] == T[i - 1 - P[i]] ) {
    			P[i]++;
    		}
    		if( i + P[i] > R) {
    			C = i;
    			R = i + P[i];
    		}
    	}
    	int max_len = 0;
    	int center = 0;
    	for(int i = 1;i<T.length() - 1;i++) {
    		if(P[i] > max_len) {
    			max_len = P[i];
    			center = i;
    		}
    	}
    	string ans = s.substr(  ( center - 1 - max_len)/2 , max_len);
    	delete[] P;
    	return ans;
    }
};

int main() {
	Solution *solver = new Solution();
	string s = "babcbabcbaccba";
	string ans = solver->longestPalindrome(s);
	cout << ans << endl;
	delete solver;
	return 0;
}


/*



class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), len = 0, start = 0;
        for(int i = 0; i < n; i++){
            int left = i, right = i;
            while(right < n && s[right+1] == s[right]) right++;
            i = right;
            while(left > 0 && right < n-1 && s[left-1] == s[right+1]){
                left--;
                right++;
            }
            
            if(len < right-left+1){
                len = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, len);
    }
};


*/