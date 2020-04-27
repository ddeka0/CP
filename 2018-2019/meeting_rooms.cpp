/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
    vector<pair<int,int>> v;
    int minMeetingRooms(vector<Interval>& intervals) {
        for(int i = 0;i<intervals.size();i++) {
            v.push_back(make_pair(intervals[i].start,1));
            v.push_back(make_pair(intervals[i].end,-1));
        }
        sort(v.begin(),v.end());
        int ans = -1;
        int top = 0;
        for(int i = 0;i<v.size();i++) {
            ans = max(ans,top);
            top = top + v[i].second;
        }
        return ans;
    }
};
