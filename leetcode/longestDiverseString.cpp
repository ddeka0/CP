#include <bits/stdc++.h>
using namespace std;

int A,B,C;

#define NOW   0
#define PREV  2
#define PPREV 3

char ch[3];

std::set<std::pair<int,char>,greater<std::pair<int,char>>> Set;

bool giveNextPossibleCharacter() {

    
    
    char excludeChar = ' ';
    if(ch[PREV] == ch[PPREV]) {
        excludeChar = ch[PREV];
    }

    if(excludeChar != 'a' && A) Set.emplace(A,'a');
    if(excludeChar != 'b' && B) Set.emplace(B,'b');
    if(excludeChar != 'c' && C) Set.emplace(C,'c');
    
    if(!Set.empty()) {
        auto&& item = *Set.begin();
        ch[NOW] = item.second;
        A = A - (ch[NOW] =='a');
        B = B - (ch[NOW] =='b');
        C = C - (ch[NOW] =='c');
        return true;
    }
    return false;
}

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        Set.clear();
        
        A = a;
        B = b;
        C = c;

        ch[NOW] = ' ';
        ch[PREV] = ' ';
        ch[PPREV] = ' ';

        std::string ans;

        while(giveNextPossibleCharacter()) {
            ans.push_back(ch[NOW]);
            ch[PPREV] = ch[PREV];
            ch[PREV] = ch[NOW];
        }
        return ans;
    }
};