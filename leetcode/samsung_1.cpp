#include <stdio.h>
const int N = 10; // 100010;
int K;
int arr[N];
long long pref[N]; // pref[0.........i] = sum(arr[0]+arr[1]+......arr[i]) from front
long long suf[N];  // suf[0.........i] = sum(arr[N-1]+arr[N-2]+......arr[i]) from back

// either search value of pref or suffix
// flag == 1 -> on prefx sum array
// flag == 0 -> on suffxi sum array
// value will always be > 0
// return -1 if could not find
int BinarySearch(long long value,bool flag) {
    int ret = -1;
    // implement and return one integer
    
    return ret;
}

int NoOfStreaks() {
    long long ans = 0;
    // suf[j] + m*T + pref[i] < K
    // m*T -> how many times full array sum needs to be taken
    // T -> full array sum
    // m -> some integer >= 0 
    // Therefore if we are able to find some j and m for an i
    // Then number of streaks ending at 
    for(int i = 0;i<N;i++) {
        // pref[i] = sum(arr[0] + arr[1] + ... + arr[i])
        // pref[i] can be <= k and pref[i] > k
        // if (pref[i] <= k) -> then find farthest j using suf array and m such that suf[j] + m*T + pref[i] < k holds
        // if (pref[i] > k) -> find j in the prefix array itself such that pref[i] - pref[j-1] < k
        if(pref[i] < K) {
            
        }else if(pref[i] > K) {
            
        }else { // pref[i] == K

        }
    }
}

int main() {
    // calculate pref[N]
    // calculate suf[N]
    // assign global K
}