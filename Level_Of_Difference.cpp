#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define MAXSTEP 20
char A[MAXN];
struct entry {
    int nr[2];
    int p;
}L[MAXN];
// L is the list of tuples that will be sorted later inside the loop
// P[stp][i] stores the sorting indices of the ith suffix after the "stp" step.
int P[MAXSTEP][MAXN],N,i,stp,cnt;
bool comp(struct entry a,struct entry b) {
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1:0) : (a.nr[0] < b.nr[0] ? 1:0);
}
int main() {
    // take the input string
    scanf("%s",A);
    printf("The String is : %s\n",A);
    for(N=strlen(A), i = 0;i<N;i++) {
        P[0][i] = A[i] - 'A';
    }
    for(stp = 1,cnt = 1; cnt >> 1 < N;stp++,cnt <<= 1) {
        for(i = 0;i<N;i++) {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < N ? P[stp-1][i+cnt]:-1;
            L[i].p = i;
        }
        sort(L,L+N,comp);
        for(i = 0;i<N;i++) {
            P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i-1].nr[1] ? P[stp][L[i-1].p] : i;
        }
    }
    for(int i = 0;i<N;i++) {
        cout << P[stp-1][i] <<" ";
    }
    cout << endl;
    return 0;
}
