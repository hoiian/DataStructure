#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int cost[10][10];
int distance[10][10];
int medium[10][10];

void allcost();
void find_path(int,int);

int main(){

    int n = 10;
    int i,j,k;
    for(i=0; i<n; i++){
            for(j=0; j<n; j++)
                cost[i][j] = 99;
    }
    cost[0][1] = 5;
    cost[0][2] = 4;
    cost[0][3] = 2;
    cost[1][4] = 3;
    cost[2][1] = 1;
    cost[2][4] = 2;
    cost[2][5] = 8;
    cost[3][2] = 1;
    cost[3][5] = 7;
    cost[4][6] = 7;
    cost[4][7] = 10;
    cost[4][8] = 15;
    cost[5][7] = 3;
    cost[6][8] = 6;
    cost[7][8] = 5;
    
    allcost();

    int a,b;
    scanf("%d%d",&a,&b);
    // for(i=0; i<n; i++){
    //         for(j=0; j<n; j++)
    //             printf("%3d",medium[i][j]);
    //         printf("\n");
    // }
    // printf("\n");
    // for(i=0; i<n; i++){
    //         for(j=0; j<n; j++)
    //             printf("%3d",distance[i][j]);
    //         printf("\n");
    // }

    if(distance[a][b] == 99) {
        printf("No solution\n");
        return 0;
    } else {
        printf("Distance:%d\n",distance[a][b]);
    }

    printf("The route for the shortest path: %d→",a);
    find_path(a,b);
    printf("%d\n",b);

    return 0;
}

void allcost() {
    int n = 10;
    int i,j,k;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            distance[i][j] = cost[i][j];
            medium[i][j] = -1;
        }
            

    for(i=0; i<n; i++)
        distance[i][i] = 0;

    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    medium[i][j] = k;
                }
                    
}

void find_path(int i,int j) {
    if(medium[i][j] == -1) return;

    find_path(i,medium[i][j]);
    printf("%d→",medium[i][j]);
    find_path(medium[i][j],j); 
}