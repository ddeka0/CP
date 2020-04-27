#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string);
int MAX_V = 100001;
std::vector<int> adj[MAX_V];
bool seen[MAX_V];
int c_size = 0;
void dfs(int u) {
    c_size++;
    seen[u] = true;
    for(auto v:adj[u]) {
        dfs(v);
    }
}
int roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> roads) {
    for(auto e:roads) {
        adj[c[0]].push_back(e[1]);
        adj[c[1]].push_back(e[0]);
    }
    std::vector<int> c_comps;
    for(int u = 1; u<=n ; u++) {
        dfs(u); // goes through a connected component and finds the size of it
        c_comps.push_back(c_size); // saves the sizes
        c_size = 0; // reset the size variable
    }

    
    return ans;

}

































int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);
        int n = stoi(nmC_libC_road[0]);
        int m = stoi(nmC_libC_road[1]);
        int c_lib = stoi(nmC_libC_road[2]);
        int c_road = stoi(nmC_libC_road[3]);
        vector<vector<int>> roads(m);
        for (int i = 0; i < m; i++) {
            roads[i].resize(2);
            for (int j = 0; j < 2; j++) {
                cin >> roads[i][j];
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        int result = roadsAndLibraries(n, c_lib, c_road, roads);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}
// lib code
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    input_string.erase(new_end, input_string.end());
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
    vector<string> splits;
    char delimiter = ' ';
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    return splits;
}
