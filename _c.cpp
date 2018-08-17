#include "_a.h"
int main() {
	for(auto e:component_to_ip) {
		cout << e.first <<" "<<e.second<<endl;
	}
	cout << "done"<<endl;
}