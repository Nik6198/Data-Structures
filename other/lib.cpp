/*#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int no_of_books=0;
struct lib
{
 char bookname[MAX];
 int price;
 char author[MAX];
};

int main()
{
int n;
struct lib s[MAX];
char temp[MAX];
int j=1,p,h,i=0;
while(j-2)
{

 printf("\nEnter the coresponding number for performing the task\n1.add\n2.remove\n3.modify\n4.display\n");
scanf("%d",&n);
switch(n)
{
  case 1:no_of_books++;
         printf("enter the book name\t");
         scanf("%s",&(s[i].bookname));
         //printf("%s",s[i].bookname);
         printf("enter author name\t");
         scanf("%s",&(s[i].author));
         printf("enter price\t\t");
         scanf("%d",&(s[i].price));
         printf("\nBook added sucessfulyy!!\n");
         i++;
         break;
  case 2:if(no_of_books>0)
         {
          printf("enter the book to be removed\t\t");
          scanf("%s",&temp);
          for(h=0;h<i;h++)
          {
            if(strcmp((s[h].bookname),temp)==0)
             {
            
               strcpy(s[h].bookname,"NULL");
               strcpy(s[h].author,"NULL");
               s[h].price=0;
               no_of_books--;
               printf("Book has been removed successfully!!\n");
               break;
              }
          }
          if(h==i)
            printf("no such book found");
         }
         else
         {printf("no more books left in the library");
         }
         break;
  case 3:printf("enter the book to be modified");
          scanf("%s",&temp);
           for(h=0;h<i;h++)
          {
            if(strcmp(s[h].bookname,temp)==0)
             {
               printf("enter th revised price\t");
               scanf("%d",&(s[h].price));
               printf("Price has been updated succesfully!!");
               break;
              }
          }
          if(h==i)
            printf("\nno such book found\n");
             
         break;
  case 4:if(i==0)
           printf("no books to display!!");
         for(h=0;h<i;h++)
         {
            
            printf("book name\t %s\nauthor\t\t%s\nprice\t\tRs%d\n",s[h].bookname,s[h].author,s[h].price);
            
          }
          break;


}
printf("\ndo you want to continue?\n1.yes\n2.no\n");
scanf("%d",&j);

}

return 0;
}101 48 96 31 1 84*/
#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
//#include <conio.h>
struct node
{
struct node *prev;
int n;
struct node *next;
}*head,*New,*temp1,*temp2,*temp3,*pivot,*last;
void insertbeg();
void insertend();
void insertpos();
void quicksort(struct node *pivot,struct node *last);
struct node* swap(struct node *pivot ,struct node *last);
void display();

int count,pcnt;
int main()
{
 int ch;
 head = NULL;
 New = temp1 = NULL;

 //clrscr();

 printf("\n 1 - Insert at beginning");
 printf("\n 2 - Insert at end");
 printf("\n 3 - Insert at position i");
 printf("\n 4 - Sort the list");
 printf("\n 5 - Display");
 printf("\n 6 - Exit");

 while (1)
 {
  printf("\n Enter choice : ");
  scanf("%d", &ch);
  switch (ch)
  {
   case 1: insertbeg();
	  break;
   case 2: insertend();
	  break;
   case 3: insertpos();
	  break;
   case 4:pivot = head;
	  last = temp1;
	  quicksort(pivot,last);
	  printf("\n\n\t\t*****Final Answer*****\n");
	  display();
	  break;
   case 5: display();
	  break;

   case 6: exit(0);

   default: printf("\n Wrong choice menu");
  }
 }
return 0;
}

void create()
{
  int data;
  New =(struct node *)malloc(1*sizeof(struct node));
  New->prev = NULL;
  New->next = NULL;
  printf("\n Enter value to node : ");
  scanf("%d", &data);
  New->n = data;
  count++;
}
void insertbeg()
{
  if (head == NULL)
  {
   create();
   head = New;
   temp1 = head;
  }
  else
  {
   create();
   New->next = head;
   head->prev = New;
   head = New;
  }
}

void insertend()
{
  if (head == NULL)
  {
   create();
   head = New;
   temp1 = head;
  }
  else
  {
   create();
   temp1->next = New;
   New->prev = temp1;
   temp1 = New;
  }
}

void insertpos()
{
 int pos, i = 2;
 printf("\n Enter position to be inserted : ");
 scanf("%d", &pos);
 temp2 = head;
 if ((pos < 1) || (pos >= count + 1))
 {
  printf("\n Position out of range to insert");
  return;
 }
 if ((head == NULL) && (pos != 1))
 {
  printf("\n Empty list cannot insert other than 1st position");
  return;
 }
 if ((head == NULL) && (pos == 1))
 {
  create();
  head = New;
  temp1 = head;
  return;
 }
 else
 {
  while (i < pos)
  {
   temp2 = temp2->next;
   i++;
  }
  create();
  New->prev = temp2;
  New->next = temp2->next;
  temp2->next->prev = New;
  temp2->next = New;
 }
}

void display()
{
  temp2 = head;
  if (temp2 == NULL)
  {
   printf("List empty to display \n");
   return;
  }

  printf("\n Linked list elements : ");

  while (temp2!= NULL)
  {
  printf(" %d ", temp2->n);
  temp2 = temp2->next;
  }

}

void quicksort(struct node *pivot,struct node *last)
{
 if(pivot!=NULL && pivot!=last && pivot!=last->next)
 {
  pivot = swap(pivot,last);
   quicksort(head,pivot->prev);
  quicksort(pivot->next,last);

 }
  /*display();
  printf("\nhead=%d\n",head->n);
  printf("\npn=%d\n",pivot->next->n);
  printf("\npl=%d\n",pivot->prev->n);*/
}

struct node* swap(struct node *pivot ,struct node *last)
{
    int t;;
    static int j=1;
    

    while(pivot->next!=NULL && pivot!=last && pivot!=last->next && last!=NULL)
    {
    // printf("%ph\n",last);
     if(pivot->n<pivot->next->n)
     {
	t = pivot->next->n;
	pivot->next->n = last->n;
	last->n = t;

	last = last->prev;
     }
     else
     {
       t = pivot->n;
       pivot->n = pivot->next->n;
       pivot->next->n = t;

       pivot = pivot->next;
       pcnt++;
     }

    }
    display();printf("%ph",pivot->prev);
return pivot;
}


