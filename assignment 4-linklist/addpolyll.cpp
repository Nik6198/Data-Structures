#include<stdio.h>
#include<malloc.h>

struct pnode
{
 int power,coeff;
 struct pnode *next;
};
typedef struct pnode pnode;

pnode* create(int);
pnode* add(pnode *,pnode *);
void print(pnode *);

int main()
{
  int n1,n2;
  pnode* p1;
  pnode* p2;
  pnode* result;
  printf("Enter the number of terms in first polynomial: ");
  scanf("%d",&n1);
  p1=create(n1);
  print(p1);
  printf("\nEnter the number of terms in second polynomial: ");
  scanf("%d",&n2);
  p2=create(n2);
  print(p2);
  result=add(p1,p2);
  printf("\n\nThe first polynomial is ");
  print(p1);
  printf("\nThe second polynomial is ");
  print(p2);
  printf("\nAddition of these two polynomial is ");
  print(result);
  return 0;
}

pnode* create(int n)
{
  int i;
  pnode *head,*p;
  head=(pnode *)malloc(sizeof(pnode));
  p=head;
  head->next=NULL;
  printf("\nEnter coefficient and power :");
  scanf("%d%d",&(p->coeff),&(p->power));
  for(i=1;i<n;i++)
  { 
    p->next=(pnode *)malloc(sizeof(pnode));
    p=p->next;
    p->next=NULL;
    printf("\nEnter the coefficient and power");
    scanf("%d%d",&(p->coeff),&(p->power));
  }
  return(head);  
}  

pnode* add(pnode *p1,pnode *p2)
{
 //printf("this is addition");
 pnode *p3,*r3;
 p3=NULL;
 while(p1!=NULL && p2!=NULL)
 {
  if(p3==NULL)
  {
   p3=r3=(pnode *)malloc(sizeof(pnode));
   p3->next=NULL;
  } 
  else if(p3!=NULL)
  {
   p3->next=(pnode *)malloc(sizeof(pnode));
   p3=p3->next;
   p3->next=NULL;
  }
  if(p1->power>p2->power)
  {
   p3->power=p1->power;
   p3->coeff=p1->coeff;
   p1=p1->next;
  } 
  else if(p2->power>p1->power)
  {
   p3->power=p2->power;
   p3->coeff=p2->coeff;
   p2=p2->next;
  } 
  else
  {
   p3->power=p1->power;
   p3->coeff=p1->coeff+p2->coeff;
   p1=p1->next;
   p2=p2->next;
  }
 } 
 while(p1!=NULL)
  {
    if(p3==NULL)
     {
       p3=r3=(pnode *)malloc(sizeof(pnode));
       p3->next=NULL;
     } 
    else
     {
        p3->next=(pnode *)malloc(sizeof(pnode));
        p3=p3->next;
        p3->next=NULL;
     }  
     p3->power=p1->power;
     p3->coeff=p1->coeff;
     p1=p1->next;
  }
 while(p2!=NULL)
  {
    if(p3==NULL)
     {
       p3=r3=(pnode *)malloc(sizeof(pnode));
       p3->next=NULL;
     } 
    else
     {
        p3->next=(pnode *)malloc(sizeof(pnode));
        p3=p3->next;
        p3->next=NULL;
     }  
     p3->power=p2->power;
     p3->coeff=p2->coeff;
     p2=p2->next;
  }
 return (r3);
}

void print(pnode *p)
{
  printf("\n");
  while(p!=NULL)
  {
    if(p->power!=0)
      printf("%dx^%d\t",p->coeff,p->power);
    else
      printf("%d",p->coeff); 
    p=p->next;
  }
}
