#include<iostream>
#include<stdio.h>
using namespace std;
#define max 50

struct stack
{
	int a[max];
	int top;
}p;
struct stack *s=&p;

void push(int);
int pop();
void quick_sort(int a[],int low,int up);
int partition(int a[],int low,int up);
int main()
{
s->top=-1;
int n;
n=6;
//int a[6]={45,23,7,0,34,100};
int a[n];
cout<<"\nenter no of elements";
cin>>n;
cout<<"\nenter elements\n";
for(int i=0;i<n;i++)
{
 cin>>a[i];
}
int low=0,up=n-1;
quick_sort(a,low,up);
 for(int i=low;i<=up;i++)
  {
    cout<<a[i]<<" ";
  }

return 0;
}
int partition(int a[],int low,int up)
{ 
  int pivot=low;
  int i=pivot+1;
  int j=up;

  while(i<=j)
  { 
  //cout<<"pivot "<<a[pivot]<<"i "<<a[i]<<"j ="<<a[j]<<endl; 
    while(a[pivot]>=a[i] && i<=up)
      i++;
    while(a[pivot]<a[j] )
      j--; 
    if(i<j)
    {
      int temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    //  cout<<a[i]<<" "<<a[j];
    } 

   }
  
  int temp=a[pivot];
  a[pivot]=a[j];
  a[j]=temp;

 
//cout<<"final pivot "<<j<<endl;;
  return j;
  
}
void quick_sort(int a[],int low,int up)
{ 
  push(low);
  push(up);
 
  while(s->top!=-1)
  {
    int u=pop(); 
    int l=pop();
  
    int j=partition(a,l,u);
  
    if(j-1>l)
    {
      push(l);
      push(j-1);
    }
    if(j+1<u)
    {
      push(j+1);
      push(u);
    }
  }
}


void push(int x)
{
	if(s->top==max-1)
	{
		printf("Stack overflow:");
	}
	else
	{
		s->top++;
		s->a[s->top]=x;
	}
}
int pop()
{
   int x;
	if(s->top ==-1)
	{
		printf("Stack underflow:");
		return(-1);
	}
	else 
	{
		x= s->a[s->top];
		s->top--;
		return x;	
	}
}
 
