#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		vector<int> startTime;
        vector<int> endTime;
		for(auto&& interval : intervals) {
            startTime.emplace_back(interval[0]);
            endTime.emplace_back(interval[1]);
		}
        std::sort(startTime.begin(),startTime.end());
        std::sort(endTime.begin(),endTime.end());

        int allocation = 0;
        for(int st = 0,reuse = 0;st < startTime.size();st++) {
            bool notAbleToReuse = (startTime[st] < endTime[reuse]);
            allocation += notAbleToReuse;
            reuse += !notAbleToReuse;
        }

		return allocation;
	}
};