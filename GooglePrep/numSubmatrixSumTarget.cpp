#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &matrix) {
    std::cout <<"-------------"<<std::endl;
    for(int i = 0;i<matrix.size();i++) {
        for(int j = 0;j<matrix[0].size();j++) {
            std::cout << matrix[i][j] <<" ";
        }
        std::cout << std::endl;
    }
    std::cout <<"-------------"<<std::endl;
}

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int res = 0;
        
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                int TopSum  = 0,LeftSum = 0,CommonSum = 0;
                if(i > 0) TopSum = matrix[i-1][j];
                if(j > 0) LeftSum = matrix[i][j-1];
                if(i > 0 and j > 0) CommonSum = matrix[i-1][j-1];
                matrix[i][j] += TopSum + LeftSum - CommonSum;
                print(matrix);

                if(matrix[i][j] == target) {
                    std::cout <<"^ +1" <<" "<<i<<" "<<j<<std::endl;
                    res++;
                }
                
                for(int k = 1;k <= j;k++) {
                    int val = matrix[i][j] - matrix[i][k-1];
                    std::cout <<val <<std::endl;
                    if(val == target) {
                        std::cout <<"*+1 "<<k<<" "<<i<<" "<<j<<std::endl;
                        res++;
                    }
                }

                for(int k = 1;k <= i;k++) {
                    int val = matrix[i][j] - matrix[k-1][j];
                    std::cout <<val <<std::endl;
                    if(val == target) {
                        std::cout <<"+1 "<<k<<" "<<i<<" "<<j<<std::endl;
                        res++;
                    }
                }
            }
        }
        return res;
    }   
};

int main() {
    Solution s;
    vector<vector<int>> v = {{0,1,0},{1,1,1},{0,1,0}};
    int target = 0;
    int ans = s.numSubmatrixSumTarget(v,target);
    std::cout <<"ans = "<< ans << std::endl;
    
}