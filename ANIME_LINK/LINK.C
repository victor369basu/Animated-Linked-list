#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
typedef struct link_list
{
    int data;
    struct link_list* link;
}lk;
lk* temp;
lk* start = NULL;
int permit()
{
   int c;
   printf("Do you want to insert more data into the list ? ( 1 -> YES and 0 -> NO) :: ");
   scanf("%d",&c);
   switch(c)
   {
      case 1:
      return create_1();

      case 0:
      temp->link = NULL;
      return main();

      default:
      printf("\nInvalid input. Enter correct input to proceed further.\n");
      return permit();

   }
}
void display_search()
{
      int i = 0;
      char msg[20];
      cleardevice();
      setcolor(WHITE);
      settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
      outtextxy(0,100,"START ->");
      for(temp = start;temp!=NULL;temp = temp->link)
      {
	 line(100+i,136,100+i,90);  // |
	 line(162+i,136,162+i,90);    //   |
	 line(100+i,136,162+i,136); //__
	 line(100+i,90,162+i,90);   //--
	 line(138+i,90,138+i,136); // midd line
	 settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
	 line(150+i,113,194+i,113);
	  outtextxy(185+i,98,">");
	 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	 moveto(111+i,110);
	 sprintf(msg,"%d",(temp->data));
	 outtext(msg);
	 i = i + 95;
      }
      settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
      outtextxy(111+i,96 ,"NULL");
     // closegraph();
}

int search_insert_list(int c)
{
      int s,z = 0;
      int flag = 0,count = 0;
      char msg1[10];
      display_search();
      for(temp = start ; temp!= NULL ; temp=temp->link )
      {
	 count = count + 1;
	 outtextxy(131+z,60,"|");
	 outtextxy(127+z,65,"v");
	 if((temp->data)==c)
	 {
	   flag = 1;
	   setcolor(RED);
	   outtextxy(131+z,60,"|");
	   outtextxy(127+z,65,"v");
	   setcolor(YELLOW);
	   break;
	 }
	delay(2000);
	setcolor(BLACK);
	outtextxy(131+z,60,"|");
	outtextxy(127+z,65,"v");
	z = z + 95;
	setcolor(WHITE);
      }
      if( flag == 1)
      {
	  outtextxy(12,200,"Searching element located at position ");
	  moveto(392,200);
	  sprintf(msg1,"%d",count);
	  outtext(msg1);
	  outtextxy(12,250,"press ENTER to continue..");
	  getch();
	  cleardevice();
	  return (1);
      }
      else
      {    setcolor(RED);
	   outtextxy(12,200,"Searching element not found. Try again.... ");
	   getch();
	   cleardevice();
	   closegraph();
	   return -1;
      }
}
int delete_element_list()
{
    if(start == NULL)
   {
      printf("\nThe list is empty.   Go to step - 1 first\n");
      getch();
      return main();
   }
   else
   {
      int p,k1,z = 0;
      int gdriver = DETECT , gmode;
      initgraph( &gdriver, &gmode ,"C:\\TC\\BGI");
      printf("\nEnter the element of the node you want to delete :: ");
      scanf("%d",&p);
      k1 = search_insert_list(p);
      if(k1<0)
      {
	  return delete_element_list();
      }
      else
      {
	  lk* prev;
	  display_search();
	  setcolor(10);
	  for(temp = start;temp->data!=p;)
	  {
	     outtextxy(131+z,60,"|");
	     outtextxy(127+z,65,"v");
	     prev = temp;
	     temp = temp->link;
	     delay(2000);
	     setcolor(BLACK);
	     outtextxy(131+z,60,"|");
	     outtextxy(127+z,65,"v");
	     z = z + 95;
	     setcolor(10);
	  }
	  setcolor(11);
	  outtextxy(131+z,60,"|");
	  outtextxy(127+z,65,"v");
	  if(temp == start)
	  {
	     delay(1500);
	     setcolor(13);
	     line(72,115,72,147);
	     delay(1500);
	     line(72,147,175,147);
	     delay(1500);
	     line(175,147,175,115);
	     settextstyle(SANS_SERIF_FONT, HORIZ_DIR,5);
	     outtextxy(167,100,"^");
	     delay(1500);
	     setcolor(BLACK);
	     settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
	     outtextxy(86,100,">");
	     setcolor(RED);
	     outtextxy(87,100,"X");
	     start = temp->link;
	     free(temp);

	     delay(2000);
	     cleardevice();
	     closegraph();
	     return display_list();

	  }
	  else
	  {
	      delay(1500);
	      setcolor(13);
	      line(72+z+10,115,72+z+10,147);
	      delay(1500);
	      line(72+z+10,147,175+z,147);
	      delay(1500);
	      line(175+z,147,175+z,115);
	      settextstyle(SANS_SERIF_FONT, HORIZ_DIR,5);
	      outtextxy(167+z,100,"^");
	      delay(1500);
	      setcolor(BLACK);
	      settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
	      outtextxy(86+z+4,98,">");
	      setcolor(RED);
	      outtextxy(87+z,100,"X");
	      prev->link = temp->link;
	      free(temp);

	      delay(2000);
	      cleardevice();
	      closegraph();
	      return display_list();

	  }
      }
   }
}
int insert_after_list()
{
    if(start == NULL)
   {
      printf("\nThe list is empty.   Go to step - 1 first\n");
      getch();
      return main();
   }
   else
   {
      int c,k,q, d = 0;
      char msg2[20];
      int gdriver = DETECT , gmode;
      initgraph( &gdriver, &gmode ,"C:\\TC\\BGI");
      printf("\nEnter element in the node after which you want to insert :: ");
      scanf("%d",&c);
      k = search_insert_list(c);
      if(k<0)
      {
	 return insert_after_list() ;
      }
      else
      {
	 lk* store = (lk*)malloc(sizeof(lk));
	 printf("\nEnter the element you want to insert: ");
	 scanf("%d",&q);
	 display_search();
	 line(142+d,62,142+d,22);  // |
	 line(215+d,62,215+d,22);  //     |
	 line(142+d,62,215+d,62); //__
	 line(142+d,22,215+d,22); //--
	 outtextxy(178+d,60,"|");
	 outtextxy(173+d,68,"V");
	 moveto(170+d,28);
	 sprintf(msg2,"%d",q);
	 outtext(msg2);
	 delay(2000);
	 setcolor(BLACK);
	 line(142+d,62,142+d,22);  // |
	 line(215+d,62,215+d,22);  //     |
	 line(142+d,62,215+d,62); //__
	 line(142+d,22,215+d,22); //--
	 outtextxy(178+d,60,"|");
	 outtextxy(173+d,68,"V");
	 moveto(170+d,28);
	 sprintf(msg2,"%d",q);
	 outtext(msg2);
	 setcolor(WHITE);
	 for(temp = start;temp->data!=c;)
	 {
	      line(142+d,62,142+d,22);  // |
	      line(215+d,62,215+d,22);  //     |
	      line(142+d,62,215+d,62); //__
	      line(142+d,22,215+d,22); //--
	      outtextxy(178+d,60,"|");
	      outtextxy(173+d,68,"V");
	      moveto(170+d,28);
	      sprintf(msg2,"%d",q);
	      outtext(msg2);
	      delay(2000);
	      setcolor(BLACK);
	      line(142+d,62,142+d,22);  // |
	      line(215+d,62,215+d,22);  //     |
	      line(142+d,62,215+d,62); //__
	      line(142+d,22,215+d,22); //--
	      outtextxy(178+d,60,"|");
	      outtextxy(173+d,68,"V");
	      moveto(170+d,28);
	      sprintf(msg2,"%d",q);
	      outtext(msg2);
	      setcolor(WHITE);
	      d = d + 95;
	      temp = temp->link;
	 }
	 line(142+d,62,142+d,22);  // |
	 line(215+d,62,215+d,22);  //     |
	 line(142+d,62,215+d,62); //__
	 line(142+d,22,215+d,22); //--
	 outtextxy(178+d,60,"|");
	 outtextxy(173+d,68,"V");
	 moveto(170+d,28);
	 sprintf(msg2,"%d",q);
	 outtext(msg2);
	 delay(2000);
	 setcolor(BLACK);
	 outtextxy(178+d,60,"|");
	 outtextxy(173+d,68,"V");
	 moveto(170+d,28);
	 sprintf(msg2,"%d",q);
	 outtext(msg2);
	 setcolor(WHITE);
	 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	 moveto(162+d,42);
	 sprintf(msg2,"%d",q);
	 outtext(msg2);
	 store->data = q;
	 delay(2000);
	 line(d+186,62,d+186,22); //middle |

	 delay(2000);
	 settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
	 setcolor(YELLOW);
	 arc(d+199,68, 358, 95, 25);
	 outtextxy(219+d,59,"V");

	 delay(2000);
	 setcolor(BLACK);
	 settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
	 line(150+d,113,194+d,113);
	 outtextxy(185+d,98,">");

	 delay(2000);
	 setcolor(YELLOW);
	 settextstyle(SANS_SERIF_FONT, HORIZ_DIR,3);
	 line(150+d,64,150+d,115);
	 outtextxy(145+d,55,"^");
	 setcolor(WHITE);
	 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	 store->link = temp->link;
	 temp->link = store;

	 delay(2000);
	 cleardevice();
	 closegraph();
	 return display_list();

      }
   }
}
int search_list()
{
   if(start == NULL)
   {
      printf("\nThe list is empty.   Go to step - 1 first\n");
      getch();
      return main();
   }
   else
   {
      int s,z = 0;
      int flag = 0,count = 0;
      char msg1[10];
      int gdriver = DETECT , gmode;
      initgraph( &gdriver, &gmode ,"C:\\TC\\BGI");
      printf("\nEnter the element you want to search :: ");
      scanf("%d",&s);
      display_search();
      for(temp = start ; temp!= NULL ; temp=temp->link )
      {
	 count = count + 1;
	 outtextxy(131+z,60,"|");
	 outtextxy(127+z,65,"v");
	 if((temp->data)==s)
	 {
	   flag = 1;
	   setcolor(RED);
	   outtextxy(131+z,60,"|");
	   outtextxy(127+z,65,"v");
	   setcolor(YELLOW);
	   break;
	 }
	delay(2000);
	setcolor(BLACK);
	outtextxy(131+z,60,"|");
	outtextxy(127+z,65,"v");
	z = z + 95;
	setcolor(WHITE);
      }
      if( flag == 1)
      {
	  outtextxy(12,200,"Searching element located at position ");
	  moveto(392,200);
	  sprintf(msg1,"%d",count);
	  outtext(msg1);
      }
      else
      {    setcolor(RED);
	   outtextxy(12,200,"Searching element not found. ");
      }
     getch();
     cleardevice();
     closegraph();
     return main();
   }
}
int display_list()
{
   clrscr();
   if(start == NULL)
   {
      printf("\nThe list is empty.   Go to step - 1 first\n");
      getch();
      return main();
   }
   else
   {
      int i = 0;
      char msg[20];
      int gdriver = DETECT , gmode;
      initgraph( &gdriver, &gmode ,"C:\\TC\\BGI");
      settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
      outtextxy(0,100,"START ->");
      for(temp = start;temp!=NULL;temp = temp->link)
      {
	 line(100+i,136,100+i,90);  // |
	 line(162+i,136,162+i,90);    //   |
	 line(100+i,136,162+i,136); //__
	 line(100+i,90,162+i,90);   //--
	 line(138+i,90,138+i,136); // midd line
	 settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
	 line(150+i,113,194+i,113);
	 outtextxy(185+i,98,">");
	 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	 moveto(111+i,110);
	 sprintf(msg,"%d",(temp->data));
	 outtext(msg);
	 i = i + 95;
      }
      settextstyle(SANS_SERIF_FONT, HORIZ_DIR,2);
      outtextxy(111+i,96 ,"NULL");
      getch();
      cleardevice();
      closegraph();
      return main();
   }
}
int create_1()
{
   lk* store = (lk*)malloc(sizeof(lk));
   printf("\nEnter element into the link list :: ");
   scanf("%d",&(store->data));
   if(start!=NULL)
   {
      temp->link = store;
      temp = store;
   }
   else
   {
      start = temp = store;
   }
   permit();
   return 0;
}
int main()
{
  int d;
  clrscr();
  printf("\nEnter your choice ::\n1. Create link list.\n2. Display the link list.\n3. Search element in the list.\n4. Insert after node.\n5. Delete node through element\n6. Exit operation.\n");
  scanf("%d",&d);
  switch(d)
  {
     case 1:
     create_1();
     break;

     case 2:
     display_list();
     break;

     case 3:
     search_list();
     break;

     case 4:
     insert_after_list();
     break;

     case 5:
     delete_element_list();
     break;

     case 6:
     return 0;

     default:
     printf("\nInvalid input.    Try again.\n");
     return main();
  }
  return 0;
}