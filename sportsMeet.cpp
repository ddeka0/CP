#include<bits/stdc++.h>
using namespace std;

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		cin>>m;
		int dist[n+1];
		int vel[n+1];

		set<pair<int, int>>d;
		vector<pair<double, int>>vect;
		for (int i = 0; i < n; ++i)
		{
			cin>>dist[i];
			d.insert(m-dist[i],i);
		}
		
		for (int i = 0; i < n; ++i)
		{
			cin>>vel[i];
		}
		for (int i = 0; i < n; ++i)
		{
			tt = 1.0*(m-dist[i])/(1.0*vel[i]);
			vect.push_back(t, i);
		}
		sort(vect.begin(), vect.end());
		for(auto e:vect){
			
		}

	}
	
}