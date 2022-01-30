#include<stdio.h>
#include<malloc.h>
#include<math.h>

struct pnode
{
 int power,coeff;
 struct pnode *next;
};

typedef struct pnode pnode;
pnode *create(int);
pnode *add(pnode *,pnode *);
pnode *mul(pnode *,pnode *);
pnode *multiply(pnode *,pnode *);
int evaluate(pnode *,int);
void print(pnode *);


int main()
{
 int i,n,n1,n2,ch,result;
 pnode *p1,*p2,*head,*sum,*product;
 
 do
 { 
   printf("\n\nEnter which operation you want to perform\n1)Add\n2)Multiply\n3)Evaluate\n4)Quit\n");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
        printf("Enter the number of terms in first polynomial: ");
        scanf("%d",&n1);
        p1=create(n1);
        print(p1);
        printf("\nEnter the number of terms in second polynomial: ");
        scanf("%d",&n2);
        p2=create(n2);
        print(p2);
	printf("\n\nThis is addition");
       	sum=add(p1,p2);
        printf("\nThe first polynomial is ");
        print(p1);
        printf("\nThe second polynomial is ");
        print(p2);
        printf("\nAddition of these two polynomial is ");
        print(sum);
	break;
     case 2:
        printf("Enter the number of terms in first polynomial: ");
        scanf("%d",&n1);
        p1=create(n1);
        print(p1);
        printf("\nEnter the number of terms in second polynomial: ");
        scanf("%d",&n2);
        p2=create(n2);
        print(p2);
	printf("\nThis is multiplication ");
        product=mul(p1,p2);
        printf("\nThe first polynomial is ");
        print(p1);
        printf("\nThe second polynomial is ");
        print(p2);
        printf("\nmultiplication of these two polynomial is ");
        print(product);
	break;
     case 3:
        pnode *c1;int n3;
        printf("Enter the number of terms in the polynomial: ");
        scanf("%d",&n3);
        c1=create(n3);
        printf("\nEnter for which polynomial you want to evaluate:");
	scanf("%d",&n);
	result=evaluate(c1,n);
        printf("\nGiven polynomial is ");
        print(c1);
	printf("\nValue of polynomial for x as %d is %d",n,result);
	break;
     case 4:
        break;
     default:break;
   }
 }while(ch!=4);
}
pnode *create(int n)
{
  int i;
  pnode *head,*p;
  head=(pnode *)malloc(sizeof(pnode));
  p=head;
  head->next=NULL;
  printf("\nEnter coefficient and power :\n");
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
pnode *add(pnode *p1,pnode *p2)
{
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
    printf("%d\t",p->coeff);
    p=p->next;
  }
}

pnode *mul(pnode *p1,pnode *p2)
{ 

 pnode *r3,*temp;
 r3=NULL;
 while(p2!=NULL)
 {
  temp=multiply(p1,p2);
  r3=add(r3,temp);
  p2=p2->next;
 }
 return (r3);
}

pnode *multiply(pnode *p1,pnode *x)
{ 
  pnode *new1,*r1;
  new1=NULL;
  while(p1!=NULL)
  {
    if(new1==NULL)
     {
       new1=r1=(pnode *)malloc(sizeof(pnode));
       r1->next=NULL;
     }
    else
     {
       r1->next=(pnode *)malloc(sizeof(pnode));
       r1=r1->next;
       r1->next=NULL;
     }
     r1->power=p1->power+x->power;
     r1->coeff=p1->coeff*x->coeff;
     p1=p1->next;
  }
 return (new1);
}
int evaluate(pnode *p1,int n)
{
 int x,n1;
 x=0;

 while(p1!=NULL)
 {
   x=x+(p1->coeff)*(pow(n,p1->power));
   p1=p1->next;
 }
 return (x);
}
