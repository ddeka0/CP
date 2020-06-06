#include <bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define debug(stuff) cout << #stuff << ": " << stuff <<endl
#define debugc(stuff) cout << #stuff << ": "; for(auto x: stuff) cout << x << " "; cout << endl;

const int N = 1000100;
long long int v[N];
long long int v1[N];
int main() {
	long long int a,b,c,d;
	cin >> a >> b >> c >> d;
	// if we fix x at k
	// y can vary from b to c
	// (x+y) can vary from (k+b) -> (k+c) by varying y from b to c
	// therefore if we have an array (arr) where index represents the (x+y) value
	// and arr[index] = number of pair of (x+y) whose sum is  = index
	// for each value of x = k_i
	// we will add one to all the elements of arr from k_i + b to k_i + c
	// to achieve this we will use difference array
	for(int x = a;x<=b;x++) {
		v[x + b]++;
		v[x + c + 1]--;
	}   
	// take cummulative sum
	for(int i = 1;i<N;i++) {
		v[i] += v[i-1];
	}
	// now v arr will have the following property
	// v[index] = ( no of paris of (x,y) where x+y = index )

	// once this array is constructed we can approach the problem in two ways:
	// first method:
	// fix longest size z to a k (for example)
	// and count no of pairs of (x+y) whose value if > k
	// add this count to the final answer
	// then take next possible value of z and do the same ....
	// for this we need to following helping value:
	// for each z_i : how many pairs of (x,y) , where x+y > z_i
    v1[0] = v[0];
    for(int i = 1;i<N;i++) {
        v1[i] = v[i];
        v1[i] += v1[i - 1];
    }
    long long int ans1 = 0;
    for(int z = c;z<=d;z++) {
    	ans1 += v1[N - 1] - v1[z];// v1[z] = total number of pairs (x,y) where
									// x+y <= z
									// v1[1e6 - 1] - v1[z] == total number of 
									// pairs (x,y) where x+y > z 
    }


    // Second, we will take sum of (x+y) = k and try to find number of 
    // z's whose value if less than k
    // if (x+y) = k and number of z < k is = m
    // then number of triangles with sum of small sides = k is = v[k] * m
    // add this to the answer and then try another (x+y) value
	long long int ans2 = 0;
	for(int s = 1;s<N;s++) {
		if(s > c) {
			ans2 += v[s] * (min((s-1)*1LL,d) - c + 1);
		}
    }
	assert(ans1 == ans2);
	cout << ans1 << endl;
}