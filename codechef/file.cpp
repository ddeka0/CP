#include <bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        int gg = 0;
        
        vector<vector<char>> maze(n, vector<char>(m,0));
        vector<vector<bool>> visited(n, vector<bool>(m,0));
        vector<vector<bool>> visited1(n, vector<bool>(m,0));

        std::queue<std::pair<int,int>> Q,Q1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char x;
                cin >>x;
                maze[i][j]=x;
                if(x == 'G') gg++; 
            }
        }
        bool done = false;
        for(int i=0;i<n and !done;i++) {
            for(int j=0;j<m and !done;j++) {
                if(maze[i][j]=='B') {
                    // BlockHim(maze, i,j);

                    visited[i][j] = 1;
                    Q.push(make_pair(i,j));
                    while(!Q.empty()) {
                        auto s = Q.front();
                        Q.pop();
                
                        for(int d = 0;d < 4;d++) {
                            int ix = s.first + dx[d];
                            int iy = s.second + dy[d];
                            if(ix >=0 && ix < n && iy >= 0 && iy < m){
                                if(maze[ix][iy] == 'B') {
                                    if(!visited[ix][iy]) {
                                        visited[ix][iy] = 1;
                                        Q.push(make_pair(ix,iy));
                                    }
                                }
                                else if(maze[ix][iy] == '.'){
                                    maze[ix][iy] = '#';
                                }
                                else if(maze[ix][iy] == '#'){
                                    // return false;
                                    // done = true;
                                }else {
                                    done = true;
                                }  
                            }
                        }
                    }
                
                }
            }
        }
        
        bool done2 = false;

        if(!done && (maze[n-1][m-1] != '#')) {
            visited1[n-1][m-1] = 1;
            Q1.push(make_pair(n-1,m-1));
            while(!Q1.empty() and !done2) {
                auto s = Q1.front();
                Q1.pop();
        
                for(int d = 0;d < 4;d++) {
                    int ix = s.first + dx[d];
                    int iy = s.second + dy[d];
                    if(ix >=0 && ix < n && iy >= 0 && iy < m) {
                        if(maze[ix][iy] == 'G') {
                            if(!visited1[ix][iy]) {
                                gg--;
                                visited1[ix][iy] = 1;
                                Q1.push(make_pair(ix,iy));
                            }
                        }
                        else if(maze[ix][iy] == '.'){
                            if(!visited1[ix][iy]) {
                                visited1[ix][iy] = 1;
                                Q1.push(make_pair(ix,iy));
                            }
                        }
                        else if(maze[ix][iy] == 'B'){
                            done2 = true;
                        }  
                    }
                }
            }
        }
        
        if(gg == 0 and maze[n-1][m-1] == '#') {
            cout <<"Yes" << endl;   
        }
        else if(gg == 0 and !done2) {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }
}
    