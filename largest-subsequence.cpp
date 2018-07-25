#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>
#include <cassert>
#include<cmath>


using namespace std;


#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS veszor<string>
#define VD veszor<double>
#define VLD veszor<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >
#define PII pair< int,int >
#define VPII vector< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define INF 9999999
#define MAXN 100002
#define MAXM 26

int a[MAXN];
int tree1[MAXN];
int tree2[MAXN];
int n;
int fll[MAXN];

int read1(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree1[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update1(int idx){
    while (idx <= n){
        tree1[idx] += 1;
        idx += (idx & -idx);
    }
}


int read2(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree2[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update2(int idx){
    while (idx <= n){
        tree2[idx] += 1;
        idx += (idx & -idx);
    }
}


void MAIN()
{
    int tmpp;
    cin>>n;
    int lx=1;
    int rx=n;
    for(int i=1;i<=n;++i)
    {
        cin>>tmpp;
        a[tmpp]=i;
    }
    int ans=min(2,n);
    for(int i=1;i<=n;++i)
    {
        cout <<"-------------------------"<<endl;
        cout <<"i = "<<i<<" lx = "<<lx<<" rx = "<<rx<<endl;
        
        int l=read1(a[i])+1;
        cout << "A: l = " <<l<<endl;
        l-=read1(lx);
        cout << "B: l = " <<l<<endl;        
        int r=read2(n-a[i]+1)+1;
        cout << "C: r = " <<r<<endl;
        r-=read2(n-rx+1);
        cout << "D: r = " <<r<<endl;
        update1(a[i]);
        update2(n-a[i]+1);
        //printf("DD\n");
        if(a[i]>lx)
            l=l+1;

        if(a[i]<rx)
            r=r+1;

        ans=max(ans,l);
        ans=max(ans,r);

        cout <<"l = "<<l <<" r = "<<r<<" ans = "<<ans<<endl;

        fll[a[i]]=1;
        for(int j=lx;j<=n;++j)
        {
            if(fll[j]==0)
            {
                lx=j;
                break;
            }
        }

        for(int j=rx;j>=1;--j)
        {
            if(fll[j]==0)
            {
                rx=j;
                break;
            }
        }
        //cout<<ans<<endl;
        cout <<"tree1"<<endl;
        for(int i = 1;i<=n;i++) {
            cout << tree1[i] <<" ";
        }
        cout << endl;
        cout <<"tree2"<<endl;
        for(int i = 1;i<=n;i++) {
            cout << tree2[i] <<" ";
        }
        cout << endl;
        cout <<"fll"<<endl;
        for(int i = 1;i<=n;i++) {
            cout << fll[i] <<" ";
        }
        cout << endl;
    } 

    cout<<ans<<endl;
}

int main()
{
	//freopen("1.txt","r",stdin);

    MAIN();

	return 0;
}

