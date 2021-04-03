#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int DFS(int ** A,int row,int col,int n,int m)
    {
    if(row<0 || row>=n || col<0 || col>=m || A[row][col]==0 || A[row][col]==-1)
        return 0;
    A[row][col] = -1;
    return 1 + DFS(A,row-1,col-1,n,m) + DFS(A,row-1,col,n,m) + DFS(A,row-1,col+1,n,m) + DFS(A,row,col-1,n,m) + DFS(A,row,col+1,n,m) + DFS(A,row+1,col-1,n,m) + DFS(A,row+1,col,n,m) + DFS(A,row+1,col+1,n,m);
}

int* onesGroups(int grid_rows, int grid_columns, int** grid, int queries_count, int* queries, int* result_count) 
{
    int temp=0,count=0,c=0;
    int len=(sizeof((queries)) / sizeof((queries)[0]));
    int *arr=malloc((grid_rows*grid_columns) * sizeof(int *));
    
    for(int i=0;i<grid_rows;i++)
        {
        for(int j=0;j<grid_columns;j++)
            {
            if(grid[i][j]==1)
                {
                temp = DFS(grid,i,j,grid_rows,grid_columns);
                if(temp!=0){
                    //arr[i] = malloc((i + 1) * sizeof(int));
					arr[c]=temp;
                    c++;
			    }
            }
        }
    }
    int arrLen=(sizeof((arr)) / sizeof((arr)[0]));
    for(int i=0;i<=len;i++){
        result_count[i]=0;
        for(int j=0;j<arrLen;j++){
            if(queries[i]==arr[j]){
                count++;
            }
            
        }

        result_count[i]=count;
        count=0;
        
    }
    
    return result_count;
}

int main()
{
    int row_size, column_size;

    scanf(" %d %d", &row_size, &column_size);

    int** grid = (int**)malloc(sizeof(int) * row_size);

    for (int i = 0; i < row_size; ++i)
        grid[i] = (int*)malloc(sizeof(int) * column_size);

    for (int i = 0; i < row_size; ++i)
    {
        for (int j = 0; j < column_size; ++j)
        {
            scanf(" %d", &grid[i][j]);
        }
    }

    int queries_size;
    printf("queries");

    scanf(" %d", &queries_size);

    int* queries = (int*)malloc(sizeof(int) * queries_size);

    for (int i = 0; i < queries_size; ++i)
        scanf(" %d", &queries[i]);

    int result_count[queries_size];

    int* groups = onesGroups(row_size, column_size, grid, queries_size, queries, result_count);

    printf("[");
    for (int i = 0; i <queries_size ; ++i)
    {
        printf("%d,", groups[i]);
    }
    printf("]");

    return 0;
}
