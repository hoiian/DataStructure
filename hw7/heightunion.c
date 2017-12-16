#include <stdio.h>
#include <stdlib.h>


// struct node{
//     int height;
//     int data;
//     struct node *parent;
// }
int parent[100];

void uni(int i, int j) {
    parent[i] = j;
}
int main() {
    int n;
    scanf("%d",&n);

    int i;
    for(i=1;i<n;i++) {
        uni(0,i);
    }
    
    printf("Node   parent\n");

    for(i=0;i<n;i++) {
        printf("%-7d%d\n",i,parent[i]);
    }
    return 0;
}