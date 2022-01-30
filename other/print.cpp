#include<iostream>
#include<stdio.h>
#define MAX 5
using namespace std;
void merge_sort(int a[],int up,int down);
void merge(int a[],int up,int down,int mid);
void bubblesort(int *a,int low,int up);
void quick_sort(int a[],int low,int up);
int partition(int a[],int low,int up);
struct queue
{
int d[MAX];
int front;
int rear;
}*q;

void enqueue(int a)
{
  if(q->rear==MAX-1)
    cout<<"queue is full";
  else if(q->front ==-1 && q->rear == -1)
  {
    q->front++;
    q->rear++;
    q->d[q->rear]=a;
}
else
{
  q->rear++;
  q->d[q->rear]=a;
}
}

int dequeue()
{
int a=-1;
if( q->front > q->rear || q->front==q->rear==-1 )
 // cout<<"queue is empty";
   return 0;
else if(q->front == 0 && q->rear ==0)
{
  a=q->d[q->front];
  q->front--;
  q->rear--;  
}
else
{
  a=q->d[q->front];
  q->front++;
}
return a;
}

int check(int *t,int *i,int *pages,int pno)
{
  if(*t==0)
  {
    printf("\nPrinter %d\t job %d done in %d time",pno,*i,*pages/10);
    if(*i<=MAX)
      {
      *pages=dequeue();      
      *t=*pages/10;
      printf("%d %d",q->rear,q->front);
      }
    (*i)++;
    return 0;
  }
  else
  {
    (*t)--;
    return 1;
  }
  
}
void printer1(int *time1)
{
  int t,i=1,k=1;
  int pages=dequeue();
  t=pages/10;
  while(t>0 || i<=MAX)
  { 
     (*time1)++;
     printf("%d\t",*time1);
     if(k<=MAX)
       k++;
     check(&t,&i,&pages,1);
     bubblesort(q->d,i,k-1);
     for(int k=i;k<5;k++)
      printf("%d ",q->d[k]);
     printf("\n");
     
  }
}


int main()
{
int time1=0,t,g;
struct queue q1;
q=&q1;
q->rear=-1;
q->front=-1;
cin>>g;
for(int i=0;i<MAX;i++)
{
  cin>>t;
  enqueue(t);
}
int k=0;
//int time1=0;
for(int i=1;i<=MAX;i++)
{
  int pages=dequeue();
  int t=pages/10;
  
  while(t>0 || i<=MAX)
  {
    time1++;
    if(t==0)
    {
      if(i<=MAX)
      {
       printf("\nPrinter 1 does job %d in %d time\n",i,pages/10);
       pages=dequeue();
       t=pages/10;
      }
      i++;
    }
    else
      t-=1;
    bubblesort(q->d,i,k);
    //  quick_sort(q->d,i,k);
    if(k<MAX-1)
      k++;
  }
}
printf("total time required is %d",time1);


return 0;
}


void bubblesort(int *a,int low,int up)
{  
  printf("\n%d %d\n",low,up);
  for(int i=low;i<up;i++)
  {
    for(int j=low+1;j<=up-i+1;j++)
    {
      if(a[i]>a[j])
      {
        int temp=a[j];
        a[j]=a[i];
        a[i]=temp;
      }    
    }
  }
  for(int i=low;i<=up;i++)
    printf("%d ",a[i]);
}
int partition(int a[],int low,int up)
{ 
  int pivot=low;
  int i=pivot+1;
  int j=up;
  while(i<=j)
  {  
    while(a[pivot]>a[i] )
      i++;
    while(a[pivot]<a[j] )
      j--; 
    if(i<j)
    {
      int temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    } 
   }
  
  int temp=a[pivot];
  a[pivot]=a[j];
  a[j]=temp;
 
  return j;
  
}
void quick_sort(int a[],int low,int up)
{ 
  if(low<up)
{
  int j=partition(a,low,up);
  quick_sort(a,low,j-1);
  quick_sort(a,j+1,up); 
}
}
