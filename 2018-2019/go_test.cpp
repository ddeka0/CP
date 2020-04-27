#include <bits/stdc++.h>
using namespace std;
int main() {

	char x,y;
	cin >> x >> y; 	// these x and y are supposed to be intergers
					// these values may be large or small
					// if small entered values will be correctly stored in x and y
					// if large values will be truncated
	
	// a small operation
	cout << x + y << endl; 	// gives correct result for x = 40 and y = 20



	cin >> x >> y;			//

	cout << x + y << endl;	// wrong result for x = 1000 and y = 1000


}