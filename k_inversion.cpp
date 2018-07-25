#include<stdio.h>
int check[10001];
int main()
{
	int num, k, p, i;
	scanf("%d %d", &num, &k);
	if(k==0) {
	    for(i=1; i<=num; i++){
	        printf("%d ", i);
	    }
	    return 0; 
	}
	for(i=2; i<=num; i++){
		if(i*(i-1)/2>=k){
			p=i;
			break;
		}
	}
	for(i=0; i<num-p; i++){
		printf("%d ", i+1);
	}
	printf("%d ", num-p*(p-1)/2+k);
	for(i=num-1; i>num-p; i--){
		if(num-p*(p-1)/2+k) printf("%d ", i);
	}
	return 0;
}