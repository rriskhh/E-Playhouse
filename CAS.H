#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<dos.h>


int rules1()
{
  clrscr();
  cleardevice();
  settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
 // printf("\n\n");
  //draw_line(60,'-');
 setcolor(14);
 outtextxy(80,20,"RULES OF THE GAME");
 // draw_line(60,'-');
   setcolor(3);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

 outtextxy(20,100,"1. Choose any number between 1 to 12.");
 outtextxy(20,120,"2. If you win you will get 10 times of money you bet");
 outtextxy(20,140,"3. If you bet on wrong number you will lose your betting amount");
delay(3500);
  return 0;
}

void desi()
{ int x=200, y=200, WBC=5;
  int const size=200;
  settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  setfillstyle(1,WBC);
  fillellipse(x,y,size,size);
  setfillstyle(1,8);
  fillellipse(x,y,size-20,size-20);
  outtextxy(x,y-(size-40),"12");
  line(200,200,170,200-(size-40));
  line(200,200,240,200-(size-40));
  outtextxy(x,y+(size-40),"6");
  line(200,200,170,200+(size-40));
  line(200,200,240,200+(size-40));
  outtextxy(x+(size-40),y,"3");
  line(200,200,200+(size-40),170);
  line(200,200,200+(size-40),240);
  outtextxy(x-(size-40),y,"9");
  line(200,200,200-(size-40),170);
  line(200,200,200-(size-40),240);
  outtextxy(x+size/3,y-2*size/3,"1");
  line(200,200,260+size/3,230-2*size/3);
  outtextxy(x+2*size/3,y-size/3,"2");
  outtextxy(x+2*size/3,y+size/3,"4");
  line(200,200,190+2*size/3,240+size/3);
  outtextxy(x+size/3,y+2*size/3,"5");
  outtextxy(x-size/3,y+2*size/3,"7");
  line(200,200,160-size/3,180+2*size/3);
  outtextxy(x-2*size/3,y+size/3,"8");
  outtextxy(x-size/3,y-2*size/3,"11");
  outtextxy(x-2*size/3,y-size/3,"10");
  line(200,200,220-2*size/3,150-size/3);
  setfillstyle(1,14);
  fillellipse(x,y,10,10);
  delay(100);

  }

int casino()
{
clrscr();
  int const size=200;
  int gd=DETECT, gm;
  initgraph(&gd,&gm,"C:\\turboc3\\bgi");
  int balanceamt,amt,no,dice;
  char playername[30],ch;
  rules1();
  clrscr();
  cleardevice();
  settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
  outtextxy(100,10,"CASINO GAME");
  printf("\n\n\n\nEnter Deposit amount to play game :");
  scanf("%d",&balanceamt);
  clrscr();
  cleardevice();
    //closegraph();



   // settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  do
  {
    clrscr();
    cleardevice();
    //gotoxy(0,60);
    printf("\n\n\n\n\tYour current balance is Rs. %d",balanceamt);
    do
    {
	printf("\n\n\tEnter money to bet: ");
	scanf("%d",&amt);
	if(amt>balanceamt)
	   printf("\n\n\tYour betting amount is more than your current balance\n\nRe-enter data\n ");
	else
	    break;
    }while(1);
    do
    {
	printf("\n\n\tEnter your lucky number to bet between 1 to 12 :");
	scanf("%d",&no);
	if(no<=0||no>12)
	   printf("\nPlease check the number!! should be between 1 to 12\n\nRe-enter data\n ");
	else
	     break;
    }while(1);

  clrscr();
  cleardevice();
  desi();
  setcolor(14);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  outtextxy(50,420,"Press Enter to roll the ball");
  getch();

  clrscr();
  cleardevice();
  for(int j=1; j<=2; ++j)
  {
  for(int i=1; i<=12; ++i)
  { setcolor(15);
    desi();
    setcolor(i);
    switch(i)
    {
    case 1 : {line(200,200,260+size/3,230-2*size/3);
		break;                            }
    case 2 : {line(200,200,200+(size-40),170);
		break;                       }
    case 3 : {line(200,200,200+(size-40),240);
		break;                        }
    case 4 : {line(200,200,190+2*size/3,240+size/3);
		break;                            }
    case 5 : {line(200,200,240,200+(size-40));
		break;                       }
    case 6 : {line(200,200,170,200+(size-40));
		break;                        }
    case 7 : {line(200,200,160-size/3,180+2*size/3);
		break;                             }
    case 8 : {line(200,200,200-(size-40),240);
		break;                        }
    case 9 : {line(200,200,200-(size-40),170);
		break;                         }
    case 10 : {line(200,200,220-2*size/3,150-size/3);
		break;                               }
    case 11 : {line(200,200,170,200-(size-40));
		break;                         }
    case 12 : {line(200,200,240,200-(size-40));
		break;                          }
	}
    delay(200);
    }
  }

  clrscr();
  cleardevice();
  setcolor(15);
  desi();
  delay(500);

  do{
 dice=(rand()%100);
  }while(dice<0||dice>12);
  clrscr();
  cleardevice();
  if(dice==no)
  {
    printf("\n\nGood Luck!! You won Rs. %d",amt*10);
    balanceamt=balanceamt+amt*10;
  }
  else
  {
     printf("\n\nBad Luck this time !! You lose Rs.%d",amt);
     balanceamt=balanceamt-amt;
  }
  delay(2500);
  setcolor(15);
  clrscr();
  cleardevice();
  desi();
  setcolor(2);
  int d=dice;
  for(int l=0;l<2;l++)
  {
  switch(d--)
    {
    case 1 : line(200,200,260+size/3,230-2*size/3);
		break;
    case 2 : line(200,200,200+(size-40),170);
		break;
    case 3 : line(200,200,200+(size-40),240);
		break;
    case 4 : line(200,200,190+2*size/3,240+size/3);
		break;
    case 5 : line(200,200,240,200+(size-40));
		break;
    case 6 : line(200,200,170,200+(size-40));
		break;
    case 7 : line(200,200,160-size/3,180+2*size/3);
		break;
    case 8 : line(200,200,200-(size-40),240);
		break;
    case 9 : line(200,200,200-(size-40),170);
		break;
    case 10 : line(200,200,220-2*size/3,150-size/3);
		break;
    case 11 : line(200,200,170,200-(size-40));
		break;
    case 12 : line(200,200,240,200-(size-40));
		break;
	}
	}
   delay(2500);
  //gotoxy(500,500);
  clrscr();
  cleardevice();
  printf("\n\n\tThe winning number was : %d",dice);
  printf("\n\n\tYou have Rs. %d\n",balanceamt);
  printf("\n\n-->Do you want to play (y/n)?:  ");
  fflush(stdin);
  scanf("%c",&ch);
  }while(ch=='Y'|| ch=='y');
  clrscr();
  cleardevice();
  //printf("\n\n\n");
  //draw_line(70,'+');
  cout<<"\t\n\n\nThe Final balance is : "<<balanceamt ;
  getch();
  return 0;
}

int main(){
clrscr();
   int i, j, gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
   setcolor(1);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
   outtextxy(150,111,"CASINO");
   clrscr();
   casino();
   cleardevice();
   
return 0;}






