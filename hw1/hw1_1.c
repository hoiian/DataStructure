#include <stdio.h>

int comp(int, int);

int main(void){
    int n,k;
    scanf("%d%d",&n,&k);
    if(n>=k){
        printf("%d\n",comp(n,k));
    }else{
        printf("n must greater than k.");
    }
    return 0;
}

int comp(int n, int k){
    if(n==k || k==0){
        return 1;
    }else {
        return comp(n-1,k)+comp(n-1,k-1);
    }
}
