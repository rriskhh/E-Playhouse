#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<iostream.h>
#include<dos.h>

#define ENTER_KEY '\r'
#define ESCAPE_KEY 27
#define SPECIAL_KEY 0
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define pos_cursor(a,b)
int x[]={20,100,200,300,400,500,630};
int y[]={20,50,100,150,200,250,300};

int welcome1(void)
{
	cleardevice();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(0,0,"Welcome to THE GAME OF MAZE");
	gotoxy(25,9);
	printf("Rules of THE GAME OF MAZE..");
	gotoxy(10,13);
	printf("1) Observe the maze carefully.");
	gotoxy(10,15);
	printf("2) Move the cursor on line only by using arrows key.");
	gotoxy(10,17);
	printf("3) Player who reachs the destination by shortest path will be the winner.");
	gotoxy(32,19);
	printf("Enjoy the Game..!!");
	gotoxy(25,25);
	printf("PRESS ENTER TO CONTINUE...");
	//cleardevice();
	delay(2500);	
return 0;
}

int loading2()
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
	return 0;
}




void maze(void)
{  clrscr();
   cleardevice();
   int m[6][7]={{1,0,1,0,1,1,1},{1,1,0,1,1,1,0},{0,1,1,0,0,1,0},{1,0,0,1,0,1,1},{1,1,1,1,1,0,0},{1,1,1,0,0,1,1}};
   int n[7][6]={{1,1,1,1,0,1},{0,1,1,1,1,1},{1,1,1,0,1,0},{1,0,1,1,1,1},{0,1,0,1,1,1},{0,1,1,0,1,1},{1,0,1,1,1,1}};
   int i, j;
   setbkcolor(15);
   setcolor(1);
   rectangle(1,1,40,40);
   rectangle(595,280,635,320);
   line(0, 20, 20, 20);

   for(j=0;j<=6;++j)
   {
       for(i=0;i<6;++i)
       {  if(m[i][j]==1)
	  {
		line(x[i],y[j],x[i+1],y[j]);

		}

	  }
	    }

     for(i=0;i<=6;++i)
   {
       for(j=0;j<6;++j)
       {  if(n[i][j]==1)
	  {   	line(x[i],y[j],x[i],y[j+1]);
		}
	  }

	  }


   }

   int shortest(void)
   {
   int i, j, gd = DETECT, gm;
   int m[6][7]={{1,0,1,0,1,1,1},{1,1,0,1,1,1,0},{0,1,1,0,0,1,0},{1,0,0,1,0,1,1},{1,1,1,1,1,0,0},{1,1,1,0,0,1,1}};
   int n[7][6]={{1,1,1,1,0,1},{0,1,1,1,1,1},{1,1,1,0,1,0},{1,0,1,1,1,1},{0,1,0,1,1,1},{0,1,1,0,1,1},{1,0,1,1,1,1}};
   initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
   int a=20,b=20, z=0;
    clrscr();
   loading2(); 
clrscr();
   cleardevice();
welcome1();
       clrscr();
cleardevice();
setcolor(1);
   maze();
   fillellipse(a,b,10,10);
   pos_cursor(a,b);
   i=0,j=0;
   setfillstyle(SOLID_FILL,5);

   unsigned char key, key2;
   do
   {

   while( (key=getch())!=ENTER_KEY)
   {
   if (key==ESCAPE_KEY)
   exit(0);
   else if (key==SPECIAL_KEY)
   {
   key2=getch();
   switch(key2)
   {
   case UP_ARROW: {
		 if ( n[i][j]!=0)
		 {b = y[--j];
		     z++;
		   setcolor(1);
		   maze();
		   setcolor(4);
		   line(x[i],y[j-1],x[i],y[j]);  }
		 else
		 {
		   outtextxy(0,400,"INVALID MOVE");} }
		 break;
   case DOWN_ARROW: {
		 if ( n[i][j]!=0)
		 {b = y[++j];
			z++;
		  setcolor(1);
		  maze();
		  setcolor(4);
		  line(x[i],y[j-1],x[i],y[j]);	}
		 else
		 {outtextxy(0,400,"INVALID MOVE");}}
		  break;
   case LEFT_ARROW:{
		if ( m[i][j]!=0)
		{ a = x[--i];
			z++;
		setcolor(1);
		maze();
		setcolor(4);
		line(x[i-1],y[j],x[i],y[j]);}
		 else
		 {outtextxy(0,400,"INVALID MOVE");} }
		 break;
   case RIGHT_ARROW: {
		  if ( m[i][j]!=0)
		 {a = x[++i];
			z++;
		  setcolor(1);
		  maze();
		  setcolor(4);
		  line(x[i-1],y[j],x[i],y[j]);	}
		 else
		 {outtextxy(0,400,"INVALID MOVE");} }
		 break;
   }


   fillellipse(a,b,10,10);



   if (a==630 && b==300)
   { delay(3000);
   outtextxy(0,400,"Reached destination");
   delay(3000);
   break;}

   }
   }
   }while(a!=630 && b!=300);
   clrscr();
   cleardevice();
   cout<<"Moves used is "<<z;
   getch();
   closegraph();
   return 0;


   }