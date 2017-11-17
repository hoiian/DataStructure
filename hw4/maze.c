#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int z;
} element; //x=row,y=col,z=dir
#define MAXSTACK 100 /*定義最大堆疊容量*/
element stack[MAXSTACK];  //堆疊的陣列宣告 
element position;
// element stack[n*m];
int top=-1;		//堆疊的頂端
int isEmpty();
void push(element); 
element pop();



int main(){
    int n,m;
    int i,j;
    int start_x,start_y;
    int exit_x,exit_y;
    scanf("%d%d",&n,&m);
    printf("%d*%d maze\n",n,m);
    
    if(n > 1001 || m > 1001){
        printf("n and m must less than 1001.\n");
        return 0;
    }

    char input[n][m];
    char maze[n+2][m+2];

    for(i=0;i<n;i++)
    {
        scanf("%s",input[i]);
        // printf("i=%d:%s",i,input[i]);
    }
    printf("input:\n");
    // display each string
    // for(i=0;i<m;i++)
    // {
    //     printf("i=%d:%s",i,input[i]);
    //     printf("\n");
    // }

     for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%c",input[i][j]);
        }
        printf("\n");
     }

    // for(i=0;i<n+2;i++){
    //     for(j=0;j<m+2;j++){
    //         maze[i][j]='0';
    //     }
    // }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            maze[i+1][j+1] = input[i][j];
        }
    }

    for(i=0;i<n+2;i++){
        maze[i][0]='1';
        maze[i][m+1]='1';
    }
    for(i=0;i<m+2;i++){
        maze[0][i]='1';
        maze[n+1][i]='1';
    }

    for(i=0;i<n+2;i++){
        for(j=0;j<m+2;j++){
            printf("%c",maze[i][j]);

            if(maze[i][j] == 's'){
                start_x = i;
                start_y = j;
            }
            if(maze[i][j] == 'd'){
                exit_x = i;
                exit_y = j;
            }
        }
        printf("\n");
    }

    printf("start:(%d,%d)\n",start_x,start_y);
    printf("exit:(%d,%d)\n",exit_x,exit_y);


    // typedef struct {
    //     short int vert;
    //     short int horiz;
    // }   offsets;
    // offsets move[8];


    int nextx,nexty,x,y,z,found = 0;
    int mark[n+2][m+2];

    for(i=0;i<n+2;i++){
        for(j=0;j<m+2;j++){
            mark[i][j] = 0;
        }
     }

    mark[start_x][start_y] = 1;

    int movex[8] = {-1,-1,0,1,1,1,0,-1};
    int movey[8] = {0,1,1,1,0,-1,-1,-1};

    stack[0].x = start_x;
    stack[0].y = start_y;
    stack[0].z = 0;
    // printf("x%d,y%d,z%d\n",stack[0].x,stack[0].y,stack[0].z);

    top = 0;

    // position = stack[0]; // take the top element from stack.
    // x = position.x;
    // y = position.y;
    // z = position.z;
    // printf("x%d,y%d,z%d\n",x,y,z);

    while(top>-1 && !found) {
        position = pop(); // take the top element from stack.
        x = position.x;
        y = position.y;
        z = position.z;
        // printf("~x%d,y%d,z%d\n",x,y,z);
        while(z<8 && !found){
            nextx = x + movex[z];
            nexty = y + movey[z];
            // printf("nextx:%d,nexty:%d\n",nextx,nexty);
            if(nextx == exit_x && nexty == exit_y )
                found = 1;
            else if(maze[nextx][nexty] == '0' && !mark[nextx][nexty]) {
                mark[nextx][nexty] = 1;
                position.x = x;
                position.y = y;
                position.z = ++z;
                push(position);
                x = nextx;
                y = nexty;
                z = 0;
                // printf("^~~~~~\n");
            }
            else ++z;
        }

    }
    
    if(found) {
        for(i=1;i<=top;i++)
        {
            // printf("%2d%5d",stack[i].x,stack[i].y);
            // printf("\n");
            maze[stack[i].x][stack[i].y] = '*';
        }
        // printf("%2d%5d\n",x,y);
        maze[x][y] = '*';

        printf("result:\n");
        for(i=1;i<n+1;i++){
            for(j=1;j<m+1;j++){
                printf("%c",maze[i][j]);
            }
            printf("\n");
        }

        printf("%d steps\n",(top+3));
    }

    return 0;
}

int isEmpty(){
	if(top==-1){
		return 1; 
	}else{
		return 0;
	}
} 
/*將指定的資料存入堆疊*/
void push(element item){
	if(top>=MAXSTACK){
		printf("堆疊已滿,無法再加入\n");	
	}else{
		stack[++top]=item;
	}
 
} 
/*從堆疊取出資料*/
element pop(){
	if(isEmpty()){
		printf("堆疊已空\n");
	}else{
        // printf("top:%d\n",top);
        // printf("pop:x%d,y%d,z%d\n",stack[top].x,stack[top].y,stack[top].z);
		return stack[top--]; 
    }
}