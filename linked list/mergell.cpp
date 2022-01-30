#include<iostream>
using namespace std;
#define ll linkedlist
struct ll
{
  int i;
  int a;
  struct ll* nxt;
};
 
typedef struct ll ll;

void merge_sort(ll*,int up,int down);
void merge(ll*,int up,int down,int mid);
int main()
{ 
int n=9;
//int a[n]={45,23,67,35,76,2,90,65,34};
ll *head=NULL,*p;
cout<<"\nenter no of elements";
cin>>n;
cout<<"\nenter elements\n";
for(int i=0;i<n;i++)
{
  if(head==NULL)
  {
    head=p=new ll;
    head->i=i;
    head->nxt=NULL;
    cin>>head->a;
  }
  else
  {
    p->nxt=new ll;
    p=p->nxt;
    cin>>p->a;
    p->i=i;
  }
}
int up=0;
int down=n-1;
merge_sort(head,up,down); 
cout<<"Final : ";
for(ll* t=head;t!=NULL;t=t->nxt)
{
  cout<<t->a<<" ";
}
return 0;
}

void merge_sort(ll* a,int up,int down)
{
int mid=(up+down)/2;
if(up<down)
 {
  merge_sort(a,up,mid);
  merge_sort(a,mid+1,down);
  merge(a,up,down,mid);
 }
}

void merge(ll* a,int up,int down,int mid)
{
 int i=up,j=mid+1;
 //int temp[(down-up+1)];
 int k=0;
 ll *p1,*p2,*t=NULL,*t2;
 while(i<=mid && j<=down)
  {

    for( p1=a;p1->i!=i;p1=p1->nxt);
  
    for(p2=a;p2->i!=j;p2=p2->nxt);
  //cout<<"i "<<p1->a<<"j "<<p2->a<<" "<<mid<<endl;
    if(p1->a < p2->a)
     { 
       if(t==NULL)
       {
         t=t2=new ll;
         t->nxt=NULL;
         t->i=k;
         t->a=p1->a;
         p1=p1->nxt;
         i++;
         k++;
        // cout<<t->a<<endl;
         //temp[k++]=a[i++];
       }
       else
       {
         t2->nxt=new ll;
         t2=t2->nxt;
         t2->nxt=NULL;
         t2->i=k;
         t2->a=p1->a;
         p1=p1->nxt;
        // cout<<t2->a<<endl;
         k++;
         i++;
       }
     } 
    else
     {  
       if(t==NULL)
       {
         t=t2=new ll;
         t->nxt=NULL;
         t->i=k;
         t->a=p2->a;
         p2=p2->nxt;
         k++;
         j++;
        // cout<<t->a<<endl;
         //temp[k++]=a[i++];
       }
       else
       {
         t2->nxt=new ll;
         t2=t2->nxt;
         t2->nxt=NULL;
         t2->i=k;
         t2->a=p2->a;
         p2=p2->nxt;
        // cout<<t2->a<<endl;
         k++;
         j++;
       }
       //temp[k++]=a[j++];
     }   
  }
 while(i<=mid)
  { 
    if(t==NULL)
    {
      t=t2=new ll;
      t->nxt=NULL;
      t->i=k;
      t->a=p1->a;
      p1=p1->nxt;
     // cout<<t->a<<endl;
      k++;
      i++;
         //temp[k++]=a[i++];
    }
    else
    {
      t2->nxt=new ll;
      t2=t2->nxt;
      t2->nxt=NULL;
      t2->i=k;
      t2->a=p1->a;
      p1=p1->nxt;
     // cout<<t2->a<<endl;
      k++;
      i++;
    }
	//temp[k++]=a[i++];
  }
 while(j<=down)
  {
    if(t==NULL)
    {
      t=t2=new ll;
      t->nxt=NULL;
      t->i=k;
      t->a=p2->a;
      p2=p2->nxt;
     // cout<<t->a<<endl;
      k++;
      j++;
         //temp[k++]=a[i++];
    }
    else
    {
      t2->nxt=new ll;
      t2=t2->nxt;
      t2->nxt=NULL;
      t2->i=k;
      t2->a=p2->a;
      p2=p2->nxt;
    //  cout<<t2->a<<endl;
      k++;
      j++;
    }
    //temp[k++]=a[j++];
  }

 for( p1=a;p1->i!=up;p1=p1->nxt);
 for(int l=0;l<k;l++)
 { 
   p1->a=t->a;
   //cout<<"final "<<p1->a<<" ";;
   p1=p1->nxt;
   t=t->nxt;
  // a[g+up]=temp[g];
   
 }//cout<<endl;

 
}
