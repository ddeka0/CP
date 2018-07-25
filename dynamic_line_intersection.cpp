#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the dynamicLineIntersection function below.
 */
void dynamicLineIntersection(int n) {
    vector<int> arr(100001,0);
   vector< vector<int> > Matrix(501, vector<int>(501, 0)); 
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        if(x=='+'||x=='-'){
            int k,b;
            cin>>k>>b;
            
            if(k>500){   
                
                if(x=='+'){
                    for(int temp=(-1)*b/k;(temp*k+b)<=100000;temp++){
                        arr[temp*k+b]+=1;
                    }
                }else{
                    for(int temp=(-1)*b/k;(temp*k+b)<=100000;temp++){
                        arr[temp*k+b]-=1;
                    }       
                }
            
            }
            else{

                if(x=='+'){
                    Matrix[k][b%k]+=1;
                }
                else{
                    Matrix[k][b%k]-=1;
                }
            
            }   
            
        }
       
        else{
            int q;
            int count=0;
            cin>>q;
            for(int i=1;i<501;i++){
                count+=Matrix[i][q%i];
            }
            count=count+arr[q];
            cout<<count<<endl;
        }
        
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    dynamicLineIntersection(n);

    return 0;
}