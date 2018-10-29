#include<bits/stdc++.h>
using namespace std;


bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b){ 
       return (a.first > b.first); 
}

int n, id, sn, bp, ts, total_share, ans, s, bid_price, cnt;

int main(){
	cin>>n;
	vector<pair<int, int>> user;
	for (int i = 0; i < n; ++i) {
		cin>>id>>sn>>bp>>ts;
		user.push_back(make_pair(bp, sn));
	}
	cin>>total_share;
	sort(user.begin(), user.end(), sortinrev);
	for (int i = 0; i < n;) {
		bid_price = user[i].first;
		s = user[i].second;
		cnt=1;
		for (i++; i < n; ++i) {
			if(user[i].first==bid_price){
				cnt++;
				s+=user[i].second;
			}
			else
				break;
		}
		if(cnt<=total_share) {
			if(s>=total_share){
				ans = n-i;
				break;
			}
			else{
				total_share-=s;
			}
		}else {
			cnt = cnt - total_share;
			ans = n - (i-cnt);
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}