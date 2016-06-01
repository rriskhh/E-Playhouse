#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
//#include<load.h>
//------------------------------------------------------------------------------------------------
int display_balls(int left)
{       delay(700);
	clrscr();
	cleardevice();
	int x=20,k=4;
	for(int i=0;i<21;i++)
	{
		if(i==left)	 k=15;
		setcolor(k);
		setfillstyle(SOLID_FILL,k);
		fillellipse(x,32,10,10);
		x=x+25;
	}
	return 0;
}

//------------------------------------------------------------------------------------------------
int loading()
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

//------------------------------------------------------------------------------------------------
int welcome(void)
{
	clrscr();
	cleardevice();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(0,0,"Welcome to THE GAME OF NIM");
	gotoxy(25,9);
	printf("Rules of THE GAME OF NIM..");
	gotoxy(12,13);
	printf("1) The Game contains 21 balls.");
	gotoxy(12,15);
	printf("2) You can choose maximum 3 balls.");
	gotoxy(12,17);
	printf("3) Player who picks the last ball will be the winner.");
	gotoxy(32,19);
	printf("Enjoy the Game..!!");
	gotoxy(25,25);
	printf("PRESS ENTER TO CONTINUE...");
	//cleardevice();
	delay(3500);
	return 0;
}

//------------------------------------------------------------------------------------------------
void easy_mode(int digit)
{
	clrscr();
	int num,flag=0,k;
	while(digit!=0)
	{
		display_balls(digit);
		start:
		//textcolor(3);
		printf("\n\n\n-->Your Turn: ");
		//outtextxy(100,60,"-->Your Turn:");
		scanf("%d",&num);
		if(num>3 || num<1 || (digit-num)<0)
		{
		       //	textcolor(15);
			printf("\nNumber is invalid\n");
			goto start;
		}
		flag=0;
		digit=digit-num;
		delay(1000);
		display_balls(digit);
		if(digit!=0)
		{       enter:
			k=rand() % 60000 + 0;
			if(k<10000) num=1;
			else
			{
				if(k<30000) num=2;
				else num=3;
			}
			if(digit-num<0) {goto enter;}
			digit=digit-num;
			printf("\n\n\nComputer took: %d balls",num);
			delay(1000);
			flag=1;
		}
	}
	//display_balls(digit);
	clrscr();
	cleardevice();
	setcolor(4);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	
	if(flag==0)
		{
		outtextxy(110,120,"WOWW...YOUU WIN!!");
		outtextxy(120,150,"10 POINTS TO YOUUU!");
		ofstream out;
		out.open("SCORES.txt",ios::app);
		out<<"10";
		out.close();
		}
	else
		{
		outtextxy(110,120,"SORRY..YOU DID IT WRONG");
		outtextxy(120,150,"BETTER LUCK NEXT TIME!");
		}

//	delay(2000);
	getch();

}

//------------------------------------------------------------------------------------------------
void hard_mode(int digit)
{       	
	cleardevice();
	clrscr();
	int i,flag,num,value;
	start:
	while(digit!=0)
	{
		display_balls(digit);
		printf("\n\n\n-->Your Turn: ");
		scanf("%d",&num);
		if(num>3 || num<1 || digit-num<0)
		{
			printf("\nNumber is invalid\n");
			goto start;
		}
		flag=0;
		digit=digit-num;
		delay(1000);
		display_balls(digit);
		if(digit!=0)
		{
			flag=1;
			if(digit%4==0)
			{
				digit=digit-num;
				printf("\n\n\nComputer took: %d balls",num);
				delay(300);
				display_balls(digit);
			}
			else
			{
				if(digit>4)
				{
					value=digit/4;
					num=digit-(value*4);
					digit=digit-num;
					printf("\n\n\nComputer took: %d balls",num);
					delay(1000);
					display_balls(digit);
				}
				else
				{
					 printf("\n\n\nComputer took: %d balls",digit);
					digit=0;
					delay(1000);
					display_balls(digit);
				}
			}
		 }
	 }
	//settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	//outtextxy(50,80,"PLEASE SELECT A MODE");

	clrscr();
	cleardevice();
	setcolor(4);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);

	if(flag==0)
		{
		outtextxy(110,120,"WOWW...YOUU WIN!!");
		outtextxy(120,150,"20 POINTS TO YOUUU!");
		ofstream out;
		out.open("SCORES.txt",ios::app);
		out<<"20";
		out.close();
		}
	else
		{
		outtextxy(110,120,"SORRY..YOU DID IT WRONG");
		outtextxy(120,150,"BETTER LUCK NEXT TIME!");
		}

	getch();
}

//-----------------------------------------------------------------------------------
int modes()
{
	int mode,k;
	char ch;
	setcolor(6);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(50,80,"PLEASE SELECT A MODE");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(120,120,"1) Easy  2) Hard");
       //	gotoxy(20,10);
       //	printf("1) Easy");
       //	gotoxy(20,12);
       //	printf("2.) Hard");
      //	gotoxy(25,15);
      setcolor(3);
       outtextxy(160,200,"Your Mode");
       textcolor(0);
       cscanf("%d",&mode);
       setcolor(15);
       outtextxy(160,200,"Your Mode");

	//display_balls(21);
	//if(mode!=1 || mode!=2) exit(0);
       //	else
	//{
		k=rand() % 1000 + 0;
		if(k<500)
		{      // gotoxy(100,50);
			setcolor(1);
		       outtextxy(80,270,"Hurray!!..You get the First Turn..");
			delay(1200);
			if(mode==1) 	easy_mode(21);
			else 	hard_mode(21);
		}
		else
		{       //gotoxy(100,50);
			setcolor(1);

			outtextxy(80,270,"Oops!!..Computer gets the First Turn..");
			delay(1200);
			clrscr();
			cleardevice();
			printf("Computer Took 1 ball");
			delay(1500);
			if(mode==1)	 easy_mode(20);
			else 	hard_mode(20);
		}
	//}
	return 0;
}

//----------------------------------------------------------------------------------------
int game_of_nim()
{
	int k;
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	loading();
	k=rand() % 20 + 0;
	if(k>10) {printf("Sorry..! The game could not load"); getch(); exit(0);}
	welcome();
	display_balls(21);
	modes();
	return 0;
}

