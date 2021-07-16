#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxEvents(vector<vector<int>>& events) {
		int nEvent = events.size();

		std::priority_queue<int,vector<int>,greater<int>> minHeap;
		
		std::sort(events.begin(),events.end());

		int i = 0;
		int ld = 0;
		int ans = 0;

		while(i < nEvent) {
			
			if(minHeap.empty()) ld = events[i][0] - 1;

			if(ld + 1 == events[i][0] || minHeap.empty()) {
				minHeap.emplace(events[i][1]);
				while((i + 1) < nEvent && events[i][0] == events[i+1][0]) {
					minHeap.emplace(events[i+1][1]);
					i++;
				}
                i++;
			}
			ld++;
			minHeap.pop();
			ans++;
			while(!minHeap.empty() && minHeap.top() <= ld) minHeap.pop();
		}

		while(!minHeap.empty()) {
			ld++;
			minHeap.pop();
			ans++;
			while(!minHeap.empty() && minHeap.top() <= ld) minHeap.pop();
		}

		return ans;
	}
};