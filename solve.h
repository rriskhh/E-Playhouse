#include <stdio.h>
#include<conio.h>
#include<iostream.h>
#include<fstream.h>
int FindUnassignedLocation(int grid[9][9],int &row,int &col)
{
	for (row= 0; row< 9; row++)
	{
		for (col = 0; col < 9; col++)
		{	if (grid[row][col] == -1)
				return 1;
		}
	}
	return 0;
}

int UsedInRow(int grid[9][9],int row,int num)
{
	for (int col = 0; col < 9; col++)
	{	if (grid[row][col] == num)
			return 0;
	}
	return 1;
}

int UsedInCol(int grid[9][9], int col, int num)
{
	for (int row = 0; row <9; row++)
	{	if (grid[row][col] == num)
			return 0;
	}
	return 1;
}

int UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row <3; row++)
	{
		for (int col = 0; col <3; col++)
		{	if (grid[row+boxStartRow][col+boxStartCol] == num)
				return 0;
		}
	}
	return 1;
}

int isSafe(int grid[9][9], int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
       current column and current 3x3 box */
	int key=(UsedInRow(grid, row, num) +UsedInCol(grid, col, num) +UsedInBox(grid, row - row%3 , col - col%3, num))/3;
	return key;
}

int SolveSudoku(int grid[9][9])
{
	int row, col;

    // If there is no unassigned location, we are done
	if (FindUnassignedLocation(grid,row,col)==0)
		return 1; // success!

    // consider digits 1 to 9
	for(int num = 1; num <= 9; num++)
	{
	// if looks promising
		if (isSafe(grid, row, col, num)==1)
		{
	    // make tentative assignment
			grid[row][col] = num;

	    // return, if success, yay!
			if (SolveSudoku(grid)==1)
				return 1;
    // failure, unmake & try again
			grid[row][col] = 0;
		}
	}
	return 0; // this triggers backtracking
}

int doku(int doku[9][9],int g)
{
    // 0 means unassigned cells
	clrscr();
	int grid[9][9],i,j;
	ifstream inf("PUZZLE.txt");
	inf.seekg(g*162,ios::beg);   
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
			inf>>grid[i][j];
	}
	if (SolveSudoku(grid) == 1)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
				if(doku[i][j]!=grid[i][j]) return 0;
		}
	}
	return 1;
}