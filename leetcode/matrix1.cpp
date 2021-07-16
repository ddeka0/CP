// Fill a 3xN grid with 4 colours 

// A(n) = Number of ways 3xN grid can be filled with last coloum contains exactly 3 colours (TypeA Ending)
// B(n) = Number of ways 3xN grid can be filled with last coloum contains exactly 2 colours (TypeB Ending)
// Answer for 3XN grid = A(n) + B(n)

// Lets add the (n+1)th column
// 1. If Nth column is of TypeA: 
//     a. (n+1) column can be of TypeB in 5 ways
//     b. (n+1) column can be of TypeA in 11 ways
// 2. If Nth column is of TypeB: 
//     a. (n+1) column can be of TypeB in 7 ways
//     b. (n+1) column can be of TypeA in 10 ways

// Total Answer for the 3X(N+1) grid is = A(n+1) + B(n+1)

// Therefore the recurrece relations are:
// A(n + 1) = 11*A(n) + 10*B(n)
// B(n + 1) = 5*A(n) + 7*B(n)

// These two recurrence relation fits in to matrix exponentiation form.


#include <stdio.h>

const int MOD = 1000000007; /*Check the MOD value*/

// a <- a x b
inline void MultiplyAndAssign(long long a[2][2],long long b[2][2]) {
    static long long res[2][2];
    for(int r = 0;r<2;r++) {
        for(int c=0;c<2;c++) {
            res[r][c] = 0;
            for(int i = 0;i<2;i++) {
                res[r][c] += (a[r][i] * b[i][c])%MOD;
            }
        }
    }
    for(int i = 0;i<2;i++) {
        for(int j = 0;j<2;j++) {
            a[i][j] = res[i][j];
        }
    }
}

int main() {

    // basic matrix which needs to be multiplied again and again
    long long mat[2][2];
    mat[0][0] = 11; mat[0][1] = 10;
    mat[1][0] = 5; mat[1][1] = 7;

    // Mat will store the results after multiplication
    // Matrix multiplicative identity is identity matrix
    long long Mat[2][2];
    Mat[0][0] = 1; Mat[0][1] = 0;
    Mat[1][0] = 0; Mat[1][1] = 1;


    long long N = 500; // Actual Input

    long long n = N - 1; // Because our base case itself is for n == 1

    // Fast Exponentiation Algorithm 
    while(n > 0) {
        if(n&1) {
            // Mat <- Mat X mat
            MultiplyAndAssign(Mat,mat);
        }
        // mat <- mat X mat        
        MultiplyAndAssign(mat,mat);
        n = n/2;
    }

    long long base[2]; // for n == 1
    
    // base[0] = number of ways to fill 1 column with three colours (4*3*2)
    // base[1] = number of ways to fill 1 column with two colours (4*3*1)
    
    base[0] = 24; base[1] = 12;

    long long ans1 = 0;
    long long ans2 = 0;

    for(int i = 0;i<2;i++) {
        ans1 = (ans1 + (Mat[0][i] *1LL* base[i])%MOD)%MOD;
        ans2 = (ans2 + (Mat[1][i] *1LL* base[i])%MOD)%MOD;
    }
    
    long long ans = (ans1 + ans2)%MOD;
    
    printf("%lld\n",ans);
}