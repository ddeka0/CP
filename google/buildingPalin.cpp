#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n,q,l,r;
    
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        string str;
        int o, ans =0;
        cin>>n>>q;
        cin>>str;
        int dp[n+1][27] = {0};
        
        for(int i=0; i<str.length();i++){
            
            for(int j=0;j<27;j++){
                dp[i+1][j] = dp[i][j];
                
            }
            dp[i+1][str[i]-'A']++;
        }
        
        while(q--){
            cin>>l>>r;
            o=0;
            for(int j=0;j<27;j++){
                if((dp[r][j]-dp[l-1][j])%2)
                    o++;
                
            }
            if((r-l+1)%2){
                if(o==1)
                    ans++;
            }
            else{
                if(o==0)
                    ans++;
            }
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
}