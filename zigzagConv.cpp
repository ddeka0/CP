#include <bits/stdc++.h>
using namespace std;
string convert(string s, int numRows) {
    if(numRows == 1) {
        return s;
    }
    std::vector<string> pattern1;
    for(int i = 1;i<numRows-1;i++) {
        pattern1.push_back(std::to_string(i));
    }
    std::vector<string> pattern2(pattern1.rbegin(),pattern1.rend());
    std::vector<string> final_pattern;
    final_pattern.push_back(to_string(0));
    for(auto e:pattern1) {
        final_pattern.push_back(e);
    }
    final_pattern.push_back(to_string(numRows - 1));
    for(auto e:pattern2) {
        final_pattern.push_back(e);
    }
    std::vector<string> temp_pattern(final_pattern);

    // for(auto e:temp_pattern) {
    //     cout << e;
    // }
    // return "     kkkk";
    for(int i = 0;i<=(s.size() / final_pattern.size()) + 5;i++) {
        for(auto e:temp_pattern) {
            final_pattern.push_back(e);
        }
    }
    string zigzag[numRows];
    for(int i = 0;i<s.size();i++) {
        zigzag[stoi(final_pattern[i])] += s[i];
    }
    string res;
    for(int i = 0;i<numRows;i++) {
        res += zigzag[i];
    }
    return res;
}
int main() {
    std::cout << convert("PAYPALISHIRING",11) << std::endl;
}