#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
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
void welcome(void)
{
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
	getch();
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
		printf("\n\n\n-->Your Turn: ");
		scanf("%d",&num);
		if(num>3 || num<1 || (digit-num)<0)
		{
			printf("\nNumber is invalid\n");
			goto start;
		}
		flag=0;
		digit=digit-num;
		delay(800);
		display_balls(digit);
		if(digit!=0)
		{       enter:
			randomize();
			k=random(100);
			if(k%2==0) num=1;
			else
			{
				if(k<30000) num=2;
				else num=3;
			}
			if(digit-num<0) {goto enter;}
			digit=digit-num;
			printf("\n\n\nComputer took: %d balls",num);
			delay(800);
			flag=1;
		}
	}
	display_balls(digit);
	if(flag==0)
		printf("\n\n\n\nWow..! You Win....Congratz\nPoints Received= 10");
	else
		printf("\n\n\n\nSorry..! Computer Wins...\nBetter Luck Next Time");

	getch();

}

//------------------------------------------------------------------------------------------------
void hard_mode(int digit)
{       clrscr();
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
	if(flag==0)
		printf("\n\n\nWow..! You Win....Congratz\nPoints Received= 20");
	else
		printf("\n\n\nSorry..! Computer Wins...\nBetter Luck Next Time");

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
	gotoxy(25,15);
	printf("Your Mode: ");
	scanf("%d",&mode);
	//display_balls(21);
	//if(mode!=1 || mode!=2) exit(0);
       //	else
	//{
		randomize();
		k=random(100);
		if(k%2==0)
		{       gotoxy(100,50);
			printf("\nHurray!!..You get the First Turn..");
			delay(1200);
			if(mode==1) 	easy_mode(21);
			else 	hard_mode(21);
		}
		else
		{       gotoxy(100,50);
			printf("\nOops!!..Computer gets the First Turn..");
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
void main()
{
	int k;
	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	welcome();
	loading();
	k=rand() % 20 + 0;
	if(k>10) {printf("Sorry..! The game could not load"); getch();}
	display_balls(21);
	modes();
}

