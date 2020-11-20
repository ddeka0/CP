#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    class SegTree {
        public:
            int sz;
            vector<int> arr;            
            
            void init(int n) {
                sz = 1;
                while(sz < n) sz = sz*2;
                arr.assign(2*sz,0);
            }
            
            void build(vector<int>& _arr,int idx,int lx,int rx) {
                if(rx - lx == 1) {
                    if(lx < (int)_arr.size()) {
                        arr[idx] = _arr[lx];
                    }
                    return;
                }

                int m = (lx + rx)/2;
                build(_arr,2*idx + 1,lx,m);
                build(_arr,2*idx + 2,m,rx);
                arr[idx] = arr[2*idx + 1] + arr[2*idx + 2];

            }
            
            void build(vector<int>& _arr) {
                build(_arr,0,0,sz);
            }
            
            void Update(int i,int v,int idx,int lx,int rx) {
                if(rx - lx == 1) {
                    arr[idx] += v;
                    return;
                }
                int m = (lx + rx)/2;
                if(i < m) {
                    Update(i,v,2*idx + 1,lx,m);
                }else {
                    Update(i,v,2*idx + 2,m,rx);
                }
                arr[idx] = arr[2*idx + 1] + arr[2*idx + 2];
            }

            void Update(int i,int v) {
                Update(i,v,0,0,sz);
            }
            
            int Query(int l,int r,int idx,int lx,int rx) {
                if(lx >= r || rx <= l) return 0;
                if(lx >= l && rx <= r) return arr[idx];
                int m = (lx + rx)/2;
                int lft = Query(l,r,2*idx+1,lx,m);
                int rht = Query(l,r,2*idx+2,m,rx);
                return lft + rht;
            }

            int Query(int l,int r) {
                return Query(l,r,0,0,sz);
            }
    };
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // normalize the sum values from 0 to 3n
		vector<long long int> Sorted;
		Sorted.push_back(std::numeric_limits<long long>::min());
		vector<long long> sums(nums.size() + 1,0LL);
		Sorted.push_back(1LL*sums[0]);
		for(int i = 1;i<=nums.size();i++) {
			sums[i] = sums[i-1] + nums[i-1];
			Sorted.push_back(sums[i]);
			Sorted.push_back(lower + sums[i-1]);
			Sorted.push_back(upper + sums[i-1] + 1);
        }

		std::sort(Sorted.begin(),Sorted.end()); // normalization done        
        SegTree st;
        st.init(Sorted.size());
        vector<int> v(Sorted.size(),0);
        for(int i = 0;i<sums.size();i++) {
            v[GetPositionOfPrefSum(Sorted,sums[i])] += 1;
        }
        st.build(v);
        int ans = 0;
        for(int i = 1;i<sums.size();i++) {
            st.Update(GetPositionOfPrefSum(Sorted,sums[i-1]),-1);
            int l = GetPositionOfPrefSum(Sorted,lower + sums[i-1]);
            int r = GetPositionOfPrefSum(Sorted,upper + sums[i-1] + 1);
            int val = st.Query(l,r);
            ans += val;
        }

		return ans;
    }

	int GetPositionOfPrefSum(vector<long long>& sorted, long long val) {
		return (int)(std::lower_bound(sorted.begin(),sorted.end(),val) - sorted.begin());
	}
};

int main() {
    Solution s;
    vector<int> nums = {2,1,2,1};
    std::cout << s.countRangeSum(nums,1,3) << std::endl;
}