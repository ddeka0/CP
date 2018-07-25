#include <bits/stdc++.h>
using namespace std;

/*template code starts*/
typedef unsigned long long ULL;
typedef long long LL;
template<typename T>
void LOG(T const& t) {
	std::cout << t<<endl;
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
/* template code ends */
set<int> notifications;
vector<int> app_notification[300009];
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int n,m,x,y;
	cin >> n >> m;
	int notification_indx = 0;
	for(int i = 0;i<m;i++) {
		cin >> x >> y;
		if(x == 1) {
			notification_indx++;
			notifications.insert(notification_indx);
			app_notification[y].push_back(notification_indx);
		}else if(x == 2) {
			for(int unread_notification_index : app_notification[y]) {
				notifications.erase(unread_notification_index);
			}
			app_notification[y].clear();
		}else {
			while(!notifications.empty()) {
				auto unread_notification_index = notifications.begin();
				if(*unread_notification_index > y) break;
				else
					notifications.erase(unread_notification_index);
			}
		}
		cout << notifications.size() << endl;
	}
	return 0;
}