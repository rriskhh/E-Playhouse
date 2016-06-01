#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<fstream.h>
#include"solve.h"
//#include<load.h>
/*int show(int i,int j,char c)
{
const char ptr=*c;
outtextxy(i,j,ptr);
return 0;
}
*/
int set_zero(int,int,int,int,int,int);
char *ptr;
//******************------------*************************-------------
void result(int i)
{
cleardevice();
setcolor(4);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
if(i==1)
{
outtextxy(110,120,"CONGRATZZ..YOU SOLVED THE PUZZLE");
outtextxy(120,150,"30 Points to You!");
	ofstream out;
		out.open("SCORES.txt",ios::app);
		out<<"30";
		out.close();
	
}
else
{
outtextxy(110,120,"SORRY..YOU DID IT WRONG");
outtextxy(120,150,"BETTER LUCK NEXT TIME!");
}
getch();
}

int solu(int doku[9][9])
{
clrscr();
for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
cout<<doku[i][j]<<" ";
cout<<endl;
}
return 0;
}
int loading1()
{       clrscr();
	cleardevice();
	int i;
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(240,220,"LOADING");
	for(i=0;i<15;i++)
	{
		setcolor(i);
		setfillstyle(SOLID_FILL,i);
		delay(300);
		fillellipse(160+(20*i),250,8,8);
	}
	delay(1000);
	cleardevice();
	return 0;
}

//******************------------*************************-------------

int rules()
{
	setcolor(1);
	outtextxy(430,135,"RULES OF SU-DOKU");
	line(430,144,555,144);
	line(430,146,555,146);
	setcolor(5);
	outtextxy(390,157,"1.) '-' Your current position.");
	outtextxy(390,174,"2.) Use arrow keys to move.");
	outtextxy(390,191,"3.) INSERT to give the answer.");
//outtextxy(395,150,"Press enter after typing the answer.");
	outtextxy(390,208,"4.) BACKSPACE to delete.");
	outtextxy(390,225,"5.) ESC to exit the game.");
	outtextxy(390,242,"6.) HOME to check your answer");
	outtextxy(420,255,"and finish the game.");

//SMILEYYY!!!!
	setcolor(14);
	setfillstyle(SOLID_FILL,14);
	fillellipse(480,300,20,20);
	setcolor(0);
	setfillstyle(SOLID_FILL,0);
	fillellipse(490,295,3,3);
	fillellipse(470,295,3,3);
	line(480,299,478,306);
	line(480,299,482,306);
	arc(480,306,180,0,8);
	return 0;
}

//******************------------*************************---------------------

int default_fill(int g)  //ALREADY GIVEN NUMBERS!!!
{
	int i,j,row=0,col=0;
	//int doku[9][9]={{-1,-1,-1,-1,-9,-1,-1,-12,-1},{-13,-11,-1,-1,-1,-1,-14,-1,-1},{-1,-1,-8,-1,-1,-13,-1,-1,-7},{-1,-1,-14,-11,-1,-1,-12,-1,-6},{-8,-1,-1,-12,-14,-6,-1,-1,-13},{-12,-1,-9,-1,-1,-8,-10,-1,-1},{-10,-1,-1,-8,-1,-1,-7,-1,-1},{-1,-1,-13,-1,-1,-1,-1,-14,-12},{-1,-8,-1,-1,-13,-1,-1,-1,-1}};
/*for(i=0;i<9;i++)
{	for(j=0;j<9;j++)
	{       if(i==j) doku[i][j]=3;
		else	doku[i][j]=0;
	}
}
doku[0][0]=0;
*/
//char *ptr;
	int doku[9][9];
	ifstream inf("PUZZLE.txt");
	inf.seekg(g*162,ios::beg);
	for(i=0;i<9;i++)
	{	for(j=0;j<9;j++)
			inf>>doku[i][j];
	}
	inf.close();
//ASSGIN NUMBER!!!!!!!!!!!
	setcolor(0);
	for(i=132;i<=292;i=i+20)
	{       col=0;
		for(j=167;j<=327;j=j+20)
		{	if(doku[row][col]<-5)
			{
				set_zero(j-4,j+10,i-4,i+10,8,0);
				sprintf(ptr,"%d",doku[row][col]+15);
			 //**ptr=b[row][col];
				outtextxy(j,i,ptr);
			//free(ptr);
			}
			++col;
		}
		++row;
	}
//free(ptr);
	return 0;
}

//******************------------*************************-------------

int set_zero(int x1,int x2,int y1,int y2,int col,int val)
{
	int i,j;
//char *ptr;
	setcolor(15);
	for(j=0;j<=y2-y1;j++)
	{	for(i=x1;i<=x2;i++)
			putpixel(i,y2-j,col);
	}
	if(val!=0)
	{     sprintf(ptr,"%d",val);
	//setcolor(15);
		outtextxy(x1+4,y1+4,ptr);
	}
	free(ptr);
	return 0;
}

//******************------------*************************-------------

int move_edit(int g)
{
//char *ptr=0;
//const char *r=ptr;
	int a=71,i,j,flag=1,k=15,row=0,col=0;
	//int b[9][9]={{-1,-1,-1,-1,-9,-1,-1,-12,-1},{-13,-11,-1,-1,-1,-1,-14,-1,-1},{-1,-1,-8,-1,-1,-13,-1,-1,-7},{-1,-1,-14,-11,-1,-1,-12,-1,-6},{-8,-1,-1,-12,-14,-6,-1,-1,-13},{-12,-1,-9,-1,-1,-8,-10,-1,-1},{-10,-1,-1,-8,-1,-1,-7,-1,-1},{-1,-1,-13,-1,-1,-1,-1,-14,-12},{-1,-8,-1,-1,-13,-1,-1,-1,-1}};
	int *val,b[9][9];
	ifstream inf("PUZZLE.txt");
       inf.seekg(g*162,ios::beg);
	for(i=0;i<9;i++)
	{	for(j=0;j<9;j++)
			inf>>b[i][j];
	}
	inf.close();
//intializing the grid:
//	char c;
       /*	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		if(i==j) b[i][j]=3;
		else	b[i][j]=-1;
	}*/
	i=167; j=132;
	b[0][0]=0;
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	while(a!=27)
	{
		setcolor(k);
		if(flag==1)
		outtextxy(i,j,"-");
		k=0;
		if(b[row][col]<-2)	set_zero(i-4,i+10,j-4,j+10,8,b[row][col]+15);
		else if(b[row][col]>0)	set_zero(i-4,i+10,j-4,j+10,0,b[row][col]);
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
		{       if(b[row][col]==0 || b[row][col]==-1)
			{	flag=0;
				textcolor(0);
				cscanf("%d",val);
		       //	ptr=&c;
				sprintf(ptr,"%d",*val);
				setcolor(15);
		       //show(i,j,c);
				outtextxy(i,j,ptr);
				b[row][col]=*val;
			}
		}
		else if(a==8)
		{	if(b[row][col]>-2)
			{
				flag=1;
			//setfillstyle(SOLID_FILL,0);
			//fillellipse(i+2,j+2,8,8);
				b[row][col]=0;
				k=15;
				set_zero(i-4,i+10,j-4,j+10,0,0);
			}
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

	else if(a==71) break; 
	}
	//else if(a>=0 && a<=9) {int k=a; outtextxy(i,j,k);}
	if(a==71)
	{
	cleardevice();
	int answer=doku(b,g);
	result(answer);
	}
	return 0;
}

//******************------------*************************-------------

int drw_sudoku()
{
	//char ptr[3];

	//const char ptr[40];
	int i,j,row=0,col=0;
	//int b[9][9]={{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
	//char *ptr;
	//int b[9][9];
	/*for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		b[i][j]=-1;
	} */

	setcolor(2);  //G
	settextstyle(DEFAULT_FONT,VERT_DIR,4);
	outtextxy(110,100,"SU-DOKU");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	outtextxy(130,60,"SU-DOKU");
	setcolor(4);  //R
	rectangle(154,119,346,311);
	setcolor(15); //W
	rectangle(157,122,343,308);
//1*1 GRID!!!!!!!:
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	setcolor(15);
	for(i=160;i<=320;i=i+20)
	{
		for(j=125;j<=285;j=j+20)
			rectangle(i,j,i+20,j+20);


	}

//3*3 GRID!!!!!!!!!:
	setcolor(4);  //R
	for(i=160;i<=320;i=i+60)
	{ 	for(j=125;j<=285;j=j+60)
			rectangle(i,j,i+60,j+60);
	}
	return 0;
}

//******************------------*************************-------------

int doku()
{
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
/*int x,y;
x=getmaxx();
y=getmaxy();
*/
	int g=rand() % 1000;
//loading();
	if(g<200)g=0;
	else if(g<400) g=1;
	else if(g<600) g=2;
	else if(g<800) g=3;
	else g=4;
	loading1();
	drw_sudoku();
	rules();
	default_fill(g);
	move_edit(g);
	closegraph();
       return 1;
       //	getch();
}