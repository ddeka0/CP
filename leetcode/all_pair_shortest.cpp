// Overall algorithm is around Flyod Warshall's N^3 algorithm
#include <iostream>
#include <climits>

const int NMAX = 101;
const int INF = 1e9;

/**
 * @brief 
 * w[i][j] = stores the shortest distance between node i and j
 * Initially it stores dist(i,j) in for the given edges and INF 
 * in (i,j) pairs where distance is not given
 */

int w[NMAX][NMAX];

/**
 * @brief 
 * initDistMatix fills the 2D matrix w with INF
 */

void initDistMatix() {
    for(int i = 0;i<NMAX;i++) {
        for(int j = 0;j<NMAX;j++) {
            w[i][j] = INF;
        }
    }
}

/**
 * @brief 
 * N = Number of nodes, node numbers will be from 1 to N
 * M = Number of edges
 * K = Number of choice to add a new edge
 */
int N,M,K; // N ~ 100,K~1000

int main() {
    initDistMatix();

    std::cin >> N >> M >> K;

    int u,v,d;

    for(int i = 0;i<M;i++) {
        std::cin >> u >> v >> d;
        w[u][v] = w[v][u] = d;
    }

    // floyd warshall
    for(int k = 1;k <=N;k++) { // O(100 * 100 * 100)
        for(int i = 1;i<=N;i++) {
            for(int j = 1;j<=N;j++) {
                w[i][j] = std::min(w[i][j],w[i][k] + w[k][j]);
            }
        }
    }

    long long initialSum = 0;

    for(int i = 1;i<=N;i++) {
        for(int j = 1;j<=N;j++) {
            initialSum += w[i][j];
        }
    }
    
    std::cout <<"initialSum = "<< initialSum << std::endl;

    if(initialSum >= INF) {
        std::cout <<"DEBUG: INVALID CASE" << std::endl;
        return 0;
    }

    long long ans = ULLONG_MAX;

    for(int i = 0;i<K;i++) { // O(1000 * 100 * 100)
        std::cin >> u >> v >> d;

        if(w[u][v] > d) { // ans is going to reduce from initialSum
            
            long long newSum = initialSum;
            // try update all the pairs with the help of dist(u,v) = d;
            for(int j = 1;j<=N;j++) {
                for(int k = 1;k<=N;k++) {
                    int updated = std::min(w[i][u] + d + w[v][j], w[i][v] + d + w[u][j]);
                    int diff = w[i][j] - updated;
                    if(diff > 0) {
                        newSum = std::min(newSum,initialSum - diff);
                    }
                }
            }

            ans = std::min(ans,newSum);

        }else { // ans might going to increase from initialSum

            // forced to try this edge
            ans = std::min(ans,initialSum + d - w[u][v]);
        
        }
    }

    std::cout <<"ans = "<<ans << std::endl;
    
    return 0;
}