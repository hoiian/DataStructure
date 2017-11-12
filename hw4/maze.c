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
int top=-1;		//堆疊的頂端
int isEmpty();
void push(element); 
element pop();


int main(){
    int n,m;
    int i;
    scanf("%d%d",&n,&m);
    printf("%d*%d maze\n",n,m);
    
    if(n > 1001 || m > 1001){
        printf("n and m must less than 1001.\n");
        return 0;
    }
    char maze[n][m];
    for(i=0;i<m;i++)
    {
        scanf("%s",maze[i]);
    }

    printf("\n");
    //display each string
    for(i=0;i<m;i++)
    {
        printf("%s",maze[i]);
        printf("\n");
    }

    // typedef struct {
    //     short int vert;
    //     short int horiz;
    // }   offsets;
    // offsets move[8];

    element position;
    element stack[n*m];
    int nextx,nexty,x,y,z,found = 0;
    int mark[n][m];
    mark[0][0] = 1;
    int top = 0;

    stack[0].x = 1;
    stack[0].y = 1;
    stack[0].z = 1;

    while(top > -1 && !found) {
        position = pop();

    }
    


    int movex[8] = {-1,-1,0,1,1,1,0,-1};
    int movey[8] = {0,1,1,1,0,-1,-1,-1};

    nextx = x + movex[z];
    nexty = y + movey[z];

    
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
		return stack[top--]; 
    }
}