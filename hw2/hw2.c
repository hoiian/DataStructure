#include <stdio.h>

void hanoi(int,char,char,char);
int main(void){
    int n;
    scanf("%d",&n);
    if(n<=64 && n>=3){
        hanoi(n,'A','B','C');
    }else{
        printf("disks number should between 3 and 64.");
    }
    return 0;
}

void hanoi(int n , char a , char b, char c){
    // int i=0;
    if(n==1){
        printf("disk%d move from %c to %c.\n",n,a,c);
        // i++;
        return;
    }else{
        hanoi(n-1, a, c, b);
        printf("disk%d move from %c to %c.\n",n,a,c);
        // i++;
        hanoi(n-1,b,a,c);

    }
    // printf("%d",i);
}