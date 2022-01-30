#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define MAX 50



struct tree
{
  int data;
  struct tree* l;
  struct tree* r;
};

typedef struct tree tree;
typedef struct tree avl;

struct queue
{
  tree* d[MAX];
  int front;
  int rear;
}*q;

void enqueue(tree*);
tree* dequeue();
int isFull();
int isEmpty();
int sizeq();
tree* create(int);
void mirror(tree*);
void levelorder(tree*);
int height(tree*);


int main()
{
  int n;
  struct queue h;
  q=&h;
  q->rear=q->front=-1;
  cout<<"enter no of elements";
  cin>>n;
  tree* root=create(n);
  cout<<"\nlevelorder is\n";
  levelorder(root);cout<<endl;
  mirror(root);
  cout<<"\nmirror image of tree in level order is\n";
  levelorder(root);cout<<endl;
  cout<<"\nheight of tree is\n";
  cout<<height(root);
  return 0;
}


tree* create(int n)
{
  tree* root=NULL;
  int f;
  tree* temp=new tree();
  temp->l=NULL;
  temp->r=NULL;
  cout<<"enter the element"; 
  cin>>temp->data;
  for(int i=0;i<n;i++)
  {
    tree* q;
    if(root==NULL)
      root=temp;
    else
    {
      tree* t=root;
      while(t!=NULL)
      {
        cout<<"enter 1 for left child and 2 for right child";
        cin>>f;
        if(f==1)
        {
          q=t;
          t=t->l;
        }
        else if(f==2)
        {
          q=t;
          t=t->r;
        }
        else
          cout<<"enter valid no";
      }
      t=new tree();
      t->l=NULL;
      t->r=NULL;
      cout<<"enter the element"; 
      cin>>t->data;
      if(f==1)
        q->l=t;
      else if(f==2)
        q->r=t;
      else
        cout<<"enter valid no";
    }   
  }
  return root;
}


void levelorder(tree* r)
{
  q->rear=q->front=-1;
  if(r!=NULL)
    enqueue(r);
  while(!isEmpty())
  {
    r=dequeue();
    if(r!=NULL);
    {cout<<r->data<<" ";
    
    if(r->l!=NULL)
      enqueue(r->l);
    if(r->r!=NULL)
      enqueue(r->r);}
  }
}


void mirror(tree* r)
{
  q->rear=q->front=-1;
  if(r!=NULL)
    enqueue(r);
  while(!isEmpty())
  {
    r=dequeue();
    tree* temp=r->l;
    r->l=r->r;
    r->r=temp;
    if(r->l!=NULL)
      enqueue(r->l);
    if(r->r!=NULL)
      enqueue(r->r);
  }
}


int height(tree* r)
{
  q->rear=q->front=-1;
  int h=0;
  if(r!=NULL)
    enqueue(r);
  while(!isEmpty())
  {
    h++;
    int f=sizeq();
    while(f--)
    {
      r=dequeue();
      if(r->l!=NULL)
        enqueue(r->l);
      if(r->r!=NULL)
        enqueue(r->r);
    }    
  }
  return h;
}


void enqueue(tree* a)
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


tree* dequeue()
{
tree* a=NULL;
if( q->front > q->rear || q->front==q->rear==-1 )
  cout<<"queue is empty";
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


int isFull()
{
    if( (q->front == q->rear + 1) || (q->front == 0 && q->rear == MAX-1)) return 1;
    return 0;
}


int isEmpty()
{
    if(q->front == -1 || q->front>q->rear) return 1;
    return 0;
}


int sizeq()
{
  return (q->rear - q->front + 1);
}



