#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
/*int show(int i,int j,char c)
{
const char ptr=*c;
outtextxy(i,j,ptr);
return 0;
}
*/
int set_zero(int x1,int x2,int y1,int y2,int col)
{
  int i,j;

  for(j=0;j<=y2-y1;j++)
  {for(i=x1;i<=x2;i++)
  {
  putpixel(i,y2-j,col);
  }
  }
  return 0;
  }

int move_edit()
{
char *ptr=0;
//const char *r=ptr;
int a=71,i,j,flag=1,k=15,row=0,col=0,b[9][9];
//intializing the grid:
       //	char c;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		b[i][j]=-1;
	}

	i=167; j=132;
	b[0][0]=0;
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	while(a!=27)
{
	setcolor(k);
	if(flag==1)
	outtextxy(i,j,"-");
	k=0;
	a=getch();
	if(a==77)
	{	flag=1;
		if(col!=8)
		{	++col;
			i=i+20;
		}
		if(b[row][col]==-1)
			b[row][col]=0;
		k=15;
	}
	else if(a==80)
	{	flag=1;
		if(row!=8)
		{	++row;
			j=j+20;
		}
		if(b[row][col]==-1)
			b[row][col]=0;
		k=15;
	}
	else if(a==75)
	{	flag=1;
		if(col!=0)
		{	--col;
			i=i-20;
		}
		if(b[row][col]==-1)
			b[row][col]=0;
		k=15;
	}
	else if(a==72)
	{	flag=1;
		if(row!=0)
		{	--row;
			j=j-20;
		}
		if(b[row][col]==-1)
			b[row][col]=0;
		k=15;
	}
	else if(a==82)
	{       if(b[row][col]<1)
		{
			flag=0;
			textcolor(0);
			cscanf("%c",ptr);
		       //	ptr=&c;
			setcolor(15);
		       //show(i,j,c);
			outtextxy(i,j,ptr);
			b[row][col]=*ptr;
		}
	}
	else if(a==8)
	{	//if(b[row][col]>0)
		//{
			flag=1;
		       /*	setfillstyle(SOLID_FILL,0);
			fillellipse(i+2,j+2,8,8);
			b[row][col]=0;
			k=15;*/
			set_zero(i-4,i+10,j-4,j+10,0);
			k=15;
			//gotoxy(
			/*setcolor(0);
			outtextxy(i,j,b[row][col]);
			textcolor(0);
			cscanf("%c",ptr);
			setcolor(15);
			//gotoxy(
			outtextxy(i,j,ptr);
		       //	scanf("%d",&a);
			b[row][col]=*ptr;
			*/
	}
}
//else if(a>=0 && a<=9) {int k=a; outtextxy(i,j,k);}

return 0;
}

int drw_sudoku()
{
	char *ptr;

	//const char ptr[40];
	int i,j,row=0,col=0;
	//int b[9][9]={{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
	int b[9][9];
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{       if(row==col) b[i][j]=3;
			else	b[i][j]=-1;
			++col;
		}
		++row;
	}
	setcolor(2);  //G
	settextstyle(DEFAULT_FONT,VERT_DIR,4);
	outtextxy(110,100,"SU-DOKU");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	outtextxy(130,60,"SU-DOKU");
	setcolor(4);  //R
	rectangle(154,119,346,311);
	setcolor(15); //W
	rectangle(157,122,343,308);
//1*1 GRID:
//cout<<b[0][0];
	row=0;col=0;
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	for(i=160;i<=320;i=i+20)
	{
		for(j=125;j<=285;j=j+20)
		{	rectangle(i,j,i+20,j+20);
			if(row==col)
			{       set_zero(i+3,i+17,j+3,j+17,11);
				setcolor(5);
				sprintf(ptr,"%d",b[row][col]);//**ptr=b[row][col];
				outtextxy(i+7,j+7,ptr);
			}
			setcolor(15);
			++row;
		}
		++col;
	}
//3*3 GRID:
	setcolor(4);  //R
	for(i=160;i<=320;i=i+60)
	{ 	for(j=125;j<=285;j=j+60)
			rectangle(i,j,i+60,j+60);
	}
return 0;
}
//------------********--------------------

void main()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
/*int x,y;
x=getmaxx();
y=getmaxy();
*/
	drw_sudoku();
	move_edit();
	cleardevice();
	closegraph();
getch();
}