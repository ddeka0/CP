#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    int l, r;
    vector< map<int, int> > adj_list(n);
    for(int i=0;i<m;i++)
    {
        cin>>l>>r;
        adj_list[l][r]= 1;
        adj_list[r][l]= 1;
    }
    vector<int> visited(n,0), inq(n,0);;
    queue<int> q;
    q.push(0);
    inq[0]++;
    for(int i=0;i<n;i++)
    {
        while(!q.empty()){
            int temp = q.front();
            q.pop();

            if(adj_list[temp].size() < k )
            {
                for(auto e : adj_list[temp] ){
                    if(!inq[e.first]){
                        q.push(e.first);
                        inq[e.first]++;
                    }
                    adj_list[e.first].erase(temp);
                }
            adj_list[temp].clear();   
            }

            inq[temp] = 0;
        }

    }

    return 0;
}