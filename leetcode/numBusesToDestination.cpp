#define DEBUG
#ifdef DEBUG
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
#else
#define trace(...) (void(0))
#define debug(...) (void(0))
#define debugc(...) (void(0))

#endif

int nRoutes;

bool sourceOK = false;
bool targetOK = false;

const int N = 1000000;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        nRoutes = routes.size();

        std::unordered_map<int,vector<int>> routeOf;

        for(int r = 0;r < nRoutes;r++) {

            int m = routes[r].size();
            
            for(int i = 0;i<m;i++) {

                int thisStation = routes[r][i];

                routeOf[thisStation].push_back(r);

                sourceOK |= thisStation == source;
                targetOK |= thisStation == target;
            }
        }

        if(!sourceOK || !targetOK) return -1;
        if(source == target) return 0;

        std::queue<pair<int,int>> Q;
        
        vector<bool> visited(nRoutes,0);

        // push all the start routes with distance = 0
        for(auto && r : routeOf[source]) {
            Q.emplace(r,1);
            visited[r] = true;
        }

        bool targetFound = false;
        
        int currRoute;
        int currDist;



        while(!Q.empty() && !targetFound) {
            auto p = Q.front();
            Q.pop();

            currRoute = p.first;
            currDist = p.second;

            for(int i = 0;i<routes[currRoute].size() && !targetFound;i++) {
                int thisStation = routes[currRoute][i];

                targetFound = thisStation == target;

                for(auto && nextRoute : routeOf[thisStation]) {
                    
                    !visited[nextRoute] && [&Q,&visited,nextRoute,currDist]() -> bool {
                        Q.emplace(nextRoute,currDist+1);
                        return visited[nextRoute] = true;                    
                    }();
                }

                // this line is important to recude the BFS complexity
                // by reducing the number of edges
                
                routeOf[thisStation].clear();
            }

        }

        return targetFound ? currDist : -1;
    }
};