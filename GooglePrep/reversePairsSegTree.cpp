#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class SegTree {
        public:
        
        int sz;
        vector<int> arr;
        
        void init(int n) {
            sz = 1;
            while(sz < n) sz = sz *2;
            arr.assign(2*sz,0);
        }
        
        void update(int i,int val,int idx,int lx,int rx) {
            if(rx - lx == 1) {
                arr[idx] += val;
                return;
            }
            int m = (lx + rx)/2;
            if(i < m) {
                update(i,val,2*idx + 1,lx,m);
            }else {
                update(i,val,2*idx + 2,m,rx);
            }
            arr[idx] = arr[2*idx + 1] + arr[2*idx + 2];
        }
        
        void update(int i,int val) {
            update(i,val,0,0,sz);
        }

        int query(int l,int r,int idx,int lx,int rx) {
            if(lx >= r || rx <= l) return 0;
            if(lx >= l && rx <= r) return arr[idx];
            int m = (lx + rx)/2;
            int lft = query(l,r,2*idx + 1,lx,m);
            int rht = query(l,r,2*idx + 2,m,rx);
            return lft + rht;
        }
        
        int query(int l) {
            return query(l,sz,0,0,sz);
        }
    };
    int reversePairs(vector<int>& nums) {
        vector<long> Sorted;
        Sorted.push_back(LONG_MIN);
        for(auto&& e:nums) {
            Sorted.push_back(2*e + 1);
            Sorted.push_back(e);
        }    
        std::sort(Sorted.begin(),Sorted.end());
        SegTree st;
        st.init(Sorted.size() + 1);

        int res = 0;
        
        std::for_each(nums.begin(),nums.end(),[this,&res,&st,&Sorted](auto& _elem) {
            // std::cout <<"this num = "<<_elem << std::endl;
            int idx = GetRelativePosition(Sorted,(long)(2LL*_elem + 1));
            // std::cout <<"2*_elem + 1 = "<<2*_elem + 1<<" found at "<<idx << std::endl;
            int val = st.query(idx);
            // std::cout << val <<" added" << std::endl;
            res += val;
            idx = GetRelativePosition(Sorted,(long)(_elem));
            st.update(idx,1);   // if _elem is 10, add +1 at the position 10 in the BIT tree
            // std::cout <<"Added +1 at " <<idx << std::endl << std::endl;
        });

        return res;
    }

    template<typename T>
    int GetRelativePosition(vector<T>& sorted, T val) {
		return (int)(std::lower_bound(sorted.begin(),sorted.end(),val) - sorted.begin());
	}
};

int  main() {
    Solution s;
    vector<int> v = {3,1,0,0};
    std::cout << s.reversePairs(v) <<std::endl;
}