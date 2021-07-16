#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
		int n = boxes.size();
		
		vector<bool> fromOtherPort(n,false);
		// fromOtherPort[i] -> false ~ box[i] & box[i-1] destined to same port
		// therefore if box[i] & box[i-1] happened to be shipped in same trip
		// then delivering box[i] will not cost +1 extra trip
		for(int i = 1;i<n;i++) {
			fromOtherPort[i] = boxes[i][0] != boxes[i-1][1];
		}


		int startBox = 0;
		int portChange = 0;
		int currWeight = 0;

		vector<int> dp(n + 1, 0);

		for(int endBox = 0;endBox<n;endBox++) {

			int weight = boxes[endBox][1];

			// [startBox .. endBox] ~ # of boxes is (endBox - startBox + 1)
			if(endBox - startBox == maxBoxes) {
				currWeight -= boxes[startBox][1];
				if(fromOtherPort[startBox + 1]) portChange--;
				startBox++;
			}

			currWeight += weight;
			portChange += fromOtherPort[endBox];

			while(currWeight > maxWeight) {
				currWeight -= boxes[startBox][1];
				if(fromOtherPort[startBox + 1]) portChange--;
				startBox++;
			}

			while(startBox < endBox && dp[startBox] == dp[startBox + 1]) {
				currWeight -= boxes[startBox][1];
				if(fromOtherPort[startBox + 1]) portChange--;
				startBox++;
			}

			dp[endBox + 1] = 2 + portChange + dp[startBox];

		}  
		return dp[n];      
    }
};


int main() {


}