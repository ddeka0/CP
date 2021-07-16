#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		vector<pair<int,int>> points;
		for(auto&& interval : intervals) {
			int x = interval[0];
			int y = interval[1];
			points.emplace_back(x,1);
			points.emplace_back(y+1,-1);
		}
		std::sort(points.begin(),points.end(),[](std::pair<int,int>& x,std::pair<int,int>& y) {
			if(x.first < y.first) return true;
			if(x.first == y.first) return x.second < y.second;
			return false;
		});

		int ans = INT_MAX;
		int tans;
		for(auto&& p : points) {
			tans += p.second;
			ans = min(ans,tans);
		}

		return ans;
	}
};