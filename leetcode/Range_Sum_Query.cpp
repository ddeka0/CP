#include <bits/stdc++.h>
using namespace std;
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

class NumArray {
public:
    int *st;
    void build(int root,int ll,int rr,int l,int r,vector<int>&v) {
        if(l > r) return;
        if(ll == rr) {
            st[root] = v[ll];
            return;
        }
        int m = (ll + rr)/2;
        build(root*2,ll,m,l,min(m,r),v);
        build(root*2+1,m+1,rr,max(l,m),r,v);

    }
    
    void update(int i, int val) {
        
    }

    void update(int i, int val) {
        
    }

    NumArray(vector<int>& nums) {
        int x = (int)(ceil(log2(nums.size())));
        int max_size = 2*(int)pow(2, x) - 1;
        st = new int[max_size];
    }


    
    int sumRange(int i, int j) {
        
    }
    ~NumArray() {
        delete[] st;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main() {

}