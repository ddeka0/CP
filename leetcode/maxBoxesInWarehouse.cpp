#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int nRoom = warehouse.size();
        int nBox = boxes.size();
        
        std::stack<int> Constraints;
        Constraints.push(0);
        for(int i = 1;i<nRoom;i++) {
            if(warehouse[Constraints.top()] >= warehouse[i]) {
                Constraints.push(i);
            }
        }
        std::sort(boxes.begin(),boxes.end());
        int lastAvailableRoom = nRoom - 1;

        int boxIdx = 0;
        int nInsertedBox = 0;
        while(boxIdx < nBox && !Constraints.empty()) {
            int currBoxSize = boxes[boxIdx];
            if(currBoxSize <= warehouse[Constraints.top()] && lastAvailableRoom >= Constraints.top()) {
                nInsertedBox++;
                if(lastAvailableRoom == Constraints.top()) {
                    Constraints.pop();
                }
                lastAvailableRoom--;
            }else {
                while(!Constraints.empty()) {
                    if(currBoxSize > warehouse[Constraints.top()]) {
                        lastAvailableRoom = Constraints.top() - 1;
                        Constraints.pop();
                    }else {
                        nInsertedBox++;
                        if(lastAvailableRoom == Constraints.top()) {
                            Constraints.pop();
                        }
                        lastAvailableRoom--;
                        break;      
                    }
                }
            }
            
            boxIdx++;
        }
        return nInsertedBox;
    }
};