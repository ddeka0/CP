#include <bits/stdc++.h>
using namespace std;
template<typename T>
void LOG(T const& t) {std::cout <<t<<endl;}
template<typename First, typename ... Rest>
void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
typedef long long LL;
typedef vector<vector<LL>> matrix;
long long modpow(long long a,long long x,long long M) {
	long long res = 1;
	while(x) {if(x&1) res = (res*a)%M; a = (a*a)%M; x/=2;}
	return res;
}

const int K = 4;

matrix mat_mul(matrix A, matrix B,LL M) {
	matrix C(K+1, vector<LL>(K+1));
    for(int i = 1;i<=K;i++) {
		for(int j = 1;j<=K;j++) {
			for(int k = 1;k<=K;k++) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
			}
		}
	}
	return C;
}
matrix mat_pow(matrix A, LL p,LL M) {
    if (p == 1)
        return A;
    if (p % 2)
        return mat_mul(A, mat_pow(A, p-1,M),M);
    matrix X = mat_pow(A, p/2,M);
    return mat_mul(X, X, M);
}
#define show(a) std::cout << #a << ": " << (a) << std::endl
const LL MOD = 1000000007;
long long f[100009];
long long rf[100009];
void inv_factorials(long long M) {
	f[0] = 1;
	long long m = 100000;
	for(int i = 1;i<=m;i++) {f[i] = (f[i - 1]*i)%M;}
	rf[m] = modpow(f[m],M-2,M);
	for(int i = m - 1;i>=0;i--) {rf[i] = (rf[i+1]*(i+1))%M;}
}
long long C(int _n,int _r,long long M) {return (_r <0 || _r > _n)?0 : f[_n]*rf[_r]%M*rf[_n - _r]%M; }
void solve();
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	solve();
	return 0;
}
class node {
public:
    int value;
    node *next;
    node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};
int N = 20;
void print_nodes(node *head) {
    node *temp = head;
    while(temp) {
        cout << temp->value<<" ";
        temp = temp->next;
    }
    cout << endl;
}
void delete_group(node *head,int n,int m) {
    node *tail = head;
    bool done = false;
    while(tail and !done) {
        // skip n elements
        int k = n - 1;
        while(k--) {
            if(tail) {
                cout <<"skipped "<<tail->value <<endl;
                tail = tail->next;
            }else {
                done = true;
                break;
            }
        }
        node *last = tail;
        if(last == nullptr) {
            return;
        }
        tail = tail->next;
        last->next = nullptr;
        // delete m elements
        if(!done and tail) {
            k = m;
            while(k--) {
                node *del_node = tail;
                tail = tail->next;
                del_node->next = nullptr;
                cout <<"deleted "<<del_node->value <<endl;
                delete del_node;
                if(!tail) {
                    done = true;
                    return;
                }
            }
        }
        last->next = tail;
    }
}
void solve() {
    node *head = nullptr;
    node *tail = nullptr;
    for(int i = 1;i<=N;i++) {
        node *new_node = new node(i);
        if(head == nullptr) {
            head = new_node;
            tail = head;
        }else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    print_nodes(head);
    delete_group(head,5,3);
    print_nodes(head);
}