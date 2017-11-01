#include <stdio.h>

int board[8][8] = {1,0};
int tra(int);
int main(){
    int i,j,n;

    for(n=1;n<=8;n++){
        printf("n=%d:\n",n);
        if(tra(n)){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    printf("%2d ",board[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }else
            printf("no solution.\n\n");
    }

  //  printf("%d\n",ktmove1[i]);


}

int tra(int n){
    int ktmove1[8]={-2,-1,1,2,2,1,-1,-2};
    int ktmove2[8]={1,2,2,1,-1,-2,-2,-1};
    int nexti[8]={0};
    int nextj[8]={0};
    int exits[8]={0};
    int npos = 0;
    int i,j,k,l,m;
    int testi, testj;
    int min,mintmp;
    int a,b;

    for(a=0;a<8;a++){
        for(b=0;b<8;b++){
            board[a][b] = 0;
        }
    }
    
    i=0;
    j=0;
    board[0][0] = 1;    

    for(m=2;m<=(n*n);m++){
        for(l=0;l<8;l++)
            exits[l] = 0;
        l=0;
            for(k=0;k<8;k++){
                testi = i + ktmove1[k];
                testj = j + ktmove2[k];
                
                if(testi >= 0 && testj >=0 && testi <n && testj < n){
                    if(board[testi][testj] == 0){
                        nexti[l] = testi;
                        nextj[l] = testj;
                        //  printf("(%d,%d)\n",nexti[l],nextj[l]);
                        l++;
                    }
                    
                }
            }
            npos = l;
        
        if(npos == 0){
            return 0;
        }
        else if(npos == 1){
            min = 0;
        }
        else if(npos > 1){
            for(l=0;l<npos;l++){
                for(k=0;k<8;k++){
                    testi = nexti[l] + ktmove1[k];
                    testj = nextj[l] + ktmove2[k];
                    
                    if(testi >= 0 && testj >=0 && testi <n && testj < n){
                        if(board[testi][testj] == 0){
                            exits[l]++;
                        }
                    }
                }
            }

            mintmp = exits[0];
            min = 0;

            for(l=1; l<npos; l++){
                if(exits[l]<mintmp){
                    mintmp = exits[l];
                    min = l ;
                }
            }
            // printf("min:%d\n",l);
            // printf("pos:%d\n",npos);
            
        }
            

        i = nexti[min];
        j = nextj[min];
        board[i][j] = m;
    }
    return 1;

}