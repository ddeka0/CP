#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> pickUp;
        vector<pair<int,int>> dropOff;
        for(auto&& trip : trips) {
            int num_passengers = trip[0];
            int start_location = trip[1];
            int end_location = trip[2];
            if(num_passengers > capacity) return false;
            pickUp.emplace_back(start_location,num_passengers);
            dropOff.emplace_back(end_location,num_passengers);
        }

        std::sort(pickUp.begin(),pickUp.end());
        std::sort(dropOff.begin(),dropOff.end());
        
        int seatAllocation = 0;
        
        for(int st = 0,reuse = 0;st < pickUp.size();st++) {
            bool notAbleToReuse = (pickUp[st].first <= dropOff[reuse].first);
            if(notAbleToReuse) {
                seatAllocation += pickUp[st].second;
            }else {
                while(pickUp[st].first > dropOff[reuse].first) {
                    seatAllocation -= dropOff[reuse].second;
                    reuse++;
                }
                seatAllocation += pickUp[st].second;
            }
            std::cout <<st <<" "<<reuse<<" "<<seatAllocation <<std::endl;
        }

        return seatAllocation <= capacity;
    }
};