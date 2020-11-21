#include <bits/stdc++.h>
using namespace std;
#define SIZE 9
int matrix[9][9] = {
    {6,5,0,8,7,3,0,9,0},
    {0,0,3,2,5,0,0,0,8},
    {9,8,0,1,0,4,3,5,7},
    {1,0,5,0,0,0,0,0,0},
    {4,0,0,0,0,0,0,0,2},
    {0,0,0,0,0,0,5,0,3},
    {5,7,8,3,0,1,0,2,6},
    {2,0,0,0,4,8,9,0,0},
    {0,9,0,6,2,5,0,8,1}
};
void print_sudoku()
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int number_unassigned(int *row, int *col)
{
    int num_unassign = 0;
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(matrix[i][j] == 0)
            {
                *row = i;
                *col = j;
                num_unassign = 1;
                return num_unassign;
            }
        }
    }
    return num_unassign;
}
int is_safe(int n, int r, int c)
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        if(matrix[r][i] == n)
            return 0;
    }
    for(i=0;i<SIZE;i++)
    {
        if(matrix[i][c] == n)
            return 0;
    }
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++)
    {
        for(j=col_start;j<col_start+3;j++)
        {
            if(matrix[i][j]==n)
                return 0;
        }
    }
    return 1;
}
int solve_sudoku()
{
    int row;
    int col;
    if(number_unassigned(&row, &col) == 0)
        return 1;
    int n,i;
    for(i=1;i<=SIZE;i++)
    {
        if(is_safe(i,row,col))
        {
            matrix[row][col] = i;
            if(solve_sudoku())
                return 1;
            matrix[row][col]=0;
        }
    }
    return 0;
}
int main()
{
    if(solve_sudoku())
    {
        cout<<"The Solution is---"<<endl;
        print_sudoku();    
    }
    else
        cout<<"No Solution!"<<endl;
    return 0;
}