#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef max
#define max(a,b) a>b? a : b
#endif

int a[100][100];
int n;
int count = 0,count_for_late = 0;
int eee[100];

int FindEarlyTime(int row, int col){
	int i,j;
	int max_value = 0;
	
	if (row == 0)  //If the first node is found.
		return 0;
	else
	{
		for (i=0;i<n;i++)
			if ( a[i][row] != 0)
				max_value = max ( max_value , a[i][row] + FindEarlyTime( i , row) );  //Find the one point to it & add the value
			if (max_value == 0) 
			{
				printf("Not Feasible.");
				exit(1);
			}
        eee[i] = max_value;
		 return max_value;
	}
} 

int FindLateTime(int row , int col){
	int i,j;
	int max_value= 0;
	
	if (col == n-1) //If the Last node is found.
		return a[row][col];
	else
	{
		for (i=0;i<n;i++)
			if ( a[col][i] != 0)
				max_value = max ( max_value , a[row][col] + FindLateTime( col , i) ); ////Find the one point to it & add the value
			if (max_value == 0) 
			{
				printf("Not Feasible.");
				exit(1);
			}
			return max_value;
	}
				 
}


int main(){
	int i,j;
	int e[100],l[100];
	char string_show[2];
	int ee = 0;
	
    scanf("%d",&n);
    int input[n][4];

    for(i=0;i<n;i++){
        for(j=0;j<4;j++)
            scanf("%d",&input[i][j]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<4;j++){
            // printf("(%d,%d):%d",i+1,j+1,input[i][j]);
            a[input[i][1]][input[i][2]] = input[i][3];
        }
            // printf("\n");
    }

	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if ( a[j][i] != 0 )
			{ 
				if (i == j)
				{
					printf("The node cannot point to itself.");
					return 1;
				} 
				e[count] = FindEarlyTime(j,i);
				count++;
				if (i == n-1)
						ee = max ( ee , e[count-1] + a[j][i] ); // Get ee. 	
			} 
			
	count_for_late = count;		
	for (i=n-1;i>=0;i--)
		for (j=n-1;j>=0;j--)
			if ( a[j][i] != 0) 
				l[--count_for_late] = ee-FindLateTime(j,i);	 // calculate l from le

    printf("a.\n");
    printf("    ee  le\n");
    for(i=0;i<count;i++)
    {
        printf("%d  ",i);
        printf("%d\n",eee[i]);
    }


	printf("b.\n");
	printf("    e   l   s   c\n");
	for (i=0;i<count;i++)
	{
		printf("a%d  ",i+1);
		printf("%-4d",e[i]);
		printf("%-4d",l[i]);
		printf("%-4d",l[i]-e[i]);
        if(l[i]-e[i] == 0)
            printf("Y\n");
        else printf("N\n");
	}

//	fout = fopen("out.txt","w");
//	fclose(fout);

}
 
