#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    int N = matrix.size();
    int M = matrix[0].size();
    vector<vector<int>> Matrix(N+10,vector<int>(M+10,0));
    for(int i = 1;i<=N;i++) {
        for(int j = 1;j<=M;j++) {
            Matrix[i][j] = matrix[i-1][j-1];
        }
    }
    r = r%4;
    for(int rot = 1;rot<=r;rot++) {

        vector<vector<int>> tMat(N+10,vector<int>(M+10,0));
        for(int i = 1;i<=N;i++) {
            for(int j = 1;j<=M;j++) {
                tMat[i][j] = Matrix[i][j];
            }
        }

        // for(int row = 1;row<=N;row++) {
        //     for(int col = 1;col<=M;col++) {
        //         cout << Matrix[row][col]<<" ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        for(int d = 1;d<=min(N,M)/2;d++) {
            int top = d; int bot = N - d + 1; int left = d; int right = M - d + 1;
            
            for(int col = d+1;col<=M-d+1;col++) {
                Matrix[top][col-1] = tMat[top][col];
            }


            // for(int row = 1;row<=N;row++) {
            //     for(int col = 1;col<=M;col++) {
            //         cout << Matrix[row][col]<<" ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;

            for(int row = d+1;row<=N-d+1;row++) {
                Matrix[row-1][right] = tMat[row][right];
            }
            

            // for(int row = 1;row<=N;row++) {
            //     for(int col = 1;col<=M;col++) {
            //         cout << Matrix[row][col]<<" ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;

            for(int col = d+1;col<=M-d+1;col++) {
                Matrix[bot][col] = tMat[bot][col-1];
            }

            // for(int row = 1;row<=N;row++) {
            //     for(int col = 1;col<=M;col++) {
            //         cout << Matrix[row][col]<<" ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;

            for(int row = d+1;row<=N-d+1;row++) {
                Matrix[row][left] = tMat[row-1][left];
            }

            // for(int row = 1;row<=N;row++) {
            //     for(int col = 1;col<=M;col++) {
            //         cout << Matrix[row][col]<<" ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;

        }
        
        for(int row = 1;row<=N;row++) {
            for(int col = 1;col<=M;col++) {
                cout << Matrix[row][col]<<" ";
            }
            cout << endl;
        }
        cout << endl;
    
    }

    // for(int row = 1;row<=N;row++) {
    //     for(int col = 1;col<=M;col++) {
    //         cout << Matrix[row][col]<<" ";
    //     }
    //     cout << endl;
    // }
}

int main() {
    string mnr_temp;
    getline(cin, mnr_temp);
    vector<string> mnr = split(rtrim(mnr_temp));
    int m = stoi(mnr[0]);
    int n = stoi(mnr[1]);
    int r = stoi(mnr[2]);
    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
