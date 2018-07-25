#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q,T;
    cin>>q;
    int array[q+2]={0};
    for(int i=0; i<q; i++){
        cin>>T;
        
        if(array[T]==0){
        
            cout<<T<<"\n";
            array[T] = 1;
        
        }else{
            
            int j;
            
            for(j=T;j<q;j++){
                
                if(array[j]==0){`
                    break;
                } 
                
            }
            cout<<j+array[j]<<"\n";
            array[j]++;

        }
    }
   
    return 0;
}