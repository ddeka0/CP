// Wormhole.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
class point{
public:
	int x,y;
};
int find_min(int a[][100],int dist[],int vis[],int n)
{
	int min1=999999,index;
	for(int i=0;i<=n;i++)
	{
		if(vis[i]==0 && dist[i]<=min1)
			min1=dist[i],index=i;
	}
	return index;
}
int dijkstra(int a[][100],int n,int vis[])
{
	//vis[src]=1;
	int dist[100];
	//vis[0]=1;
	for(int i=0;i<=n;i++)
		dist[i]=999999;
	dist[0]=0;
	for(int i=0;i<=n;i++)
	{
		int temp=find_min(a,dist,vis,n);
		vis[temp]=1;
		for(int j=0;j<=n;j++)
		{
			if(!vis[j] && a[temp][j] && dist[temp]!=999999 && dist[j]>a[temp][j]+dist[temp])
				dist[j]=a[temp][j]+dist[temp];
		}
	//	cout<<dist[n]<<" ";
	}
	return dist[n];
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		point p[100];
		int w[100];
		cin>>p[0].x>>p[0].y;
		cin>>p[2*n+1].x>>p[2*n+1].y;
		int j=1;
		for(int i=1;i<=2*n;i+=2)
		{
			cin>>p[i].x>>p[i].y>>p[i+1].x>>p[i+1].y>>w[j];
			j++;
		}
		int a[100][100]={{0}};
		for(int i=0;i<=2*n+1;i++)
		{
			for(int j=i;j<=2*n+1;j++)
			{
				a[i][j]=abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);
			}
		}
		int k=1;
		for(int i=1;i<=2*n;i+=2)
		{
			a[i][i+1]=w[k];
			a[i+1][i]=w[k];
			k++;
		}
		if(n==0)
		{
			cout<<abs(p[1].x-p[0].x)+abs(p[1].y-p[0].y)<<endl;
		}
		else
		{
			int vis[100]={0};
			cout<<dijkstra(a,2*n+1,vis)<<endl;
		}
	}
	return 0;
}

