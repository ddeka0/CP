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
                // getchar();
                //std::cout <<"Query :" <<l<<" "<<r<<" "<<idx<<" "<<lx<<" "<<rx<<std::endl;
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
		//Sorted.push_back(std::numeric_limits<long long>::min());
        Sorted.push_back(-10e10*1LL);

		vector<long long> sums(nums.size() + 1,0LL);
		Sorted.push_back(1LL*sums[0]);
		for(int i = 1;i<=nums.size();i++) {
			sums[i] = sums[i-1] + nums[i-1];
			Sorted.push_back(1LL*sums[i]);
			Sorted.push_back(1LL*(1LL*lower + sums[i-1]));
			Sorted.push_back(1LL*(1LL*upper + sums[i-1] + 1LL));
            std::cout <<"pushed : "<<sums[i]<<" "<<1LL*(lower + sums[i-1]) <<" "<< 1LL*(upper + sums[i-1] + 1) << std::endl;
        }

        // std::cout <<"Sorted Size = "<<Sorted.size() << std::endl;
        // std::cout <<"Before sorting ..." << std::endl;
        // for(auto&& e:Sorted) {
        //     std::cout << e <<" ";
        // }
        // std::cout << std::endl;
		std::sort(Sorted.begin(),Sorted.end()); // normalization done
        std::cout <<"After sorting ..." << std::endl;
        for(auto&& e:Sorted) {
            std::cout << e <<" ";
        }
        std::cout << std::endl;
        
        SegTree st;
        st.init(Sorted.size());
        vector<int> v(Sorted.size(),0);
        for(int i = 0;i<sums.size();i++) {
            v[BinarySearch(Sorted,sums[i])] += 1;
        }
        std::cout <<"Ater converting them to zeros and ones" << std::endl;
        for(long long e:v) {
            std::cout << e <<" ";
        }
        std::cout << std::endl;

        st.build(v);
        
        for(long long e:st.arr) {
            std::cout << e <<" ";
        }
        std::cout << std::endl;
        int ans = 0;
        for(int i = 1;i<sums.size();i++) {
            st.Update(BinarySearch(Sorted,sums[i-1]),-1);
            int l = BinarySearch(Sorted,lower + sums[i-1]);
            std:cout <<"lower+sums[i-1] = "<<lower + sums[i-1]<<" found at "<<l<<std::endl;
            int r = BinarySearch(Sorted,upper + sums[i-1] + 1);
            std::cout <<"upper + sums[i-1] + 1 = "<<upper + sums[i-1] + 1<<" found at "<<r<<std::endl;
            std::cout <<"i = "<<i <<" l = "<<l<<" r = "<<r<< std::endl;
            // getchar();
            int val = st.Query(l,r);
            std::cout <<"ans added :" << val << std::endl;
            //ans -= st.Query(0,);
            ans += val;
        }

		return ans;
    }

	int BinarySearch(vector<long long>& sorted, long long val) {
		return (int)(std::lower_bound(sorted.begin(),sorted.end(),val) - sorted.begin());
	}
};

int main() {
    //std::cout << std::numeric_limits<long long>::min() << std::endl;
    // vector<long long> v;
    // v.push_back(-10000000);
    // v.push_back(0);

    // v.push_back(9);
    // v.push_back(-1);
    // v.push_back(0);

    // v.push_back(-1);
    // v.push_back(8);
    // v.push_back(9);

    // v.push_back(0);
    // v.push_back(-2);
    // v.push_back(-1);

    // v.push_back(0);
    // v.push_back(-1);
    // v.push_back(0);

    // std::sort(v.begin(),v.end());
    // for(auto&& e:v) {
    //     std::cout << e <<" ";
    // }
    // std::cout << std::endl;

    // return 0;

    Solution s;
    vector<int> nums = {9,-10,1,0};
    std::cout << s.countRangeSum(nums,-1,0) << std::endl;
}