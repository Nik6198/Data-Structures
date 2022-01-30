#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define MAX 50


struct tbt
{
  int data;
  long int l;
  long int r;
};

typedef struct tbt tbt;

tbt* create_tbt(int);
void inorder_tbt(tbt*);
void preorder_tbt(tbt*);

int main()
{
  tbt *t1=create_tbt(8);
  cout<<"\ninorder\n";
  inorder_tbt(t1);cout<<endl;
  cout<<"\npreorder\n";
  preorder_tbt(t1);
  return 0;
}


tbt* create_tbt(int n)
{
  tbt* dummy=new tbt;
  dummy->l=dummy->r=0;
  
  for(int i=0;i<n;i++)
  {
    if(dummy->l==0)
    {
      tbt *t=new tbt;
      cout<<"enter the element";
      cin>>t->data;
      dummy->l=(long int)t;
      t->l=-((long int)dummy);
      t->r=-((long int)dummy);
    }
    else
    {
      long int t=dummy->l;
      long int p;
      int f;
      while(t>0)
      {
        cout<<"1 for left and 2 for right";
        cin>>f;
        
        if(f==1)
        {
          p=t;
          t=((tbt*)t)->l;
        }
        else if(f==2)
        { 
          p=t;
          t=((tbt*)t)->r;  
        }    
      }
      tbt *temp=new tbt;
      cout<<"enter the element";
      cin>>temp->data;
  
      if(f==1)
      { 
        temp->l=((tbt*)p)->l;
        ((tbt*)p)->l=(long int)temp;
        temp->r=-(p);
      }
      else if(f==2)
      {
        temp->r=((tbt*)p)->r;
        ((tbt*)p)->r=(long int)temp;
        temp->l=-(p);
      }
    }
    
  }
  return dummy;
  
}


void inorder_tbt(tbt* t)
{
  long int temp=((tbt*)t)->l; 
  
  while( ((tbt*)temp)->l>0 )
  {
    temp=((tbt*)temp)->l;
  }
  
  while(temp!=(long int)t)
  {
    cout<<((tbt*)temp)->data;
  
    if( ((tbt*)temp)->r<0)
    {
      temp=-(((tbt*)temp)->r);
    }
    else
    {
      temp=((tbt*)temp)->r;
      while( ((tbt*)temp)->l>0 )
      {
        temp=((tbt*)temp)->l;
      }
    }
  }
}

void preorder_tbt(tbt *t)
{
  long int temp=((tbt*)t)->l;

  while( ((tbt*)temp)->l>0 )
  {
    cout<<((tbt*)temp)->data;
    temp=((tbt*)temp)->l;
  } 

  cout<<((tbt*)temp)->data;
  
   while(temp!=(long int)t)
  {
  
    if( ((tbt*)temp)->r<0)
    {
      temp=-(((tbt*)temp)->r);
    }
    else
    {
      temp=((tbt*)temp)->r;

      while( ((tbt*)temp)->l>0 )
      {
        cout<<((tbt*)temp)->data;
        temp=((tbt*)temp)->l;
      }
      cout<<((tbt*)temp)->data;
    }
  }
}
