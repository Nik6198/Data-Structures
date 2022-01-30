#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct ll
{
  int i;
  int a;
  struct ll* nxt;
}ll;



void quick_sort(ll* a,int low,int up);
int partition(ll* a,int low,int up);


int main()
{
int n;
n=6;
//int a[6]={45,23,7,0,34,100};
ll* head=NULL,*p;
cout<<"\nenter no of elements";
cin>>n;
cout<<"\nenter elements\n";
for(int i=0;i<n;i++)
{
  if(head==NULL)
  {
    head=p=new ll;
    p->i=i;
    p->nxt=NULL;
    cin>>p->a;
  }
  else
  {
    p->nxt=new ll;
    p=p->nxt;
    p->i=i;
    cin>>p->a;
    p->nxt=NULL;
  }
}
int low=0,up=n-1;
quick_sort(head,low,up);
 for(ll* t=head;t!=NULL;t=t->nxt)
  {
    cout<<t->a<<" ";
  }

return 0;
}


void quick_sort(ll* a,int low,int up)
{ 
  if(low<up)
{
  int j=partition(a,low,up);
  quick_sort(a,low,j-1);
  quick_sort(a,j+1,up); 
}
}


int partition(ll* a,int low,int up)
{ 
  //int pivot=low;
  
  int i=low+1;
  int j=up;
  ll *p1,*p2,*pivot;
  
  for(pivot=a;pivot->i!=low;pivot=pivot->nxt);
  for(p2=a;p2->i!=j;p2=p2->nxt);
  p1=pivot->nxt; 

  while(i<=j)
  {  
 
 // cout<<"pivot "<<pivot->a<<" i "<<p1->a<<" j "<<p2->a<<endl;
    while(pivot->a >= p1->a && i<=up)
    {
      i++;
      if(i<up)
      p1=p1->nxt;
    }
    while(pivot->a < p2->a )
    {
      j--;
      if(j>=low )
      for(p2=a;p2->i!=j;p2=p2->nxt);
    }
    if(i<j)
    {
      int temp=p1->a;
      p1->a=p2->a;
      p2->a=temp;
     // cout<<p1->a<<" "<<p2->a<<endl;
      //i++;j--;
      
    }
   // cout<<"pivot "<<pivot->a<<" i "<<p1->a<<" j "<<p2->a<<endl; 
   }
  
  int temp=pivot->a;
  pivot->a=p2->a;
  p2->a=temp;

 //cout<<"j "<<j<<endl<<endl;
  return j;
  
}
