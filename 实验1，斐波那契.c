#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	int a,b,l,r;
	for(int i=0;i<t;i++){
		scanf("%d %d %d %d",&a,&b,&l,&r);
		int num[1001]={0};
		num[0]=a%1000;
	    num[1]=b%1000;
	for(int n=2;n<=r;n++){
		num[n]=(num[n-1]+num[n-2])%1000;}
	long long all=0;
	for(l;l<=r;l++){
			all=(all+num[l])%1000;	
		}
        for (int j = l; j <= r; j++) {
            all = (all + num[j]) % 1000;  
        }

        if (all == 0) {
            printf("0\n");
        } else {
            printf("%lld\n", all);}
    }

	} 
