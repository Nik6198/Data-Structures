#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<stdlib.h>
#define MAX 20
using namespace std;

struct gll
{
  int flag;
  union
  {
    struct gll* down;
    char c;
  }u;
  struct gll* nxt;
}*g;

typedef struct gll gll;

struct stack
{
  gll* a[MAX];
  int top;
}*s;

void push(gll*);
gll* pop();
gll* create(char*);
void print(gll*);
gll* copy(gll*);
gll* copy1(gll*);//without recursion
int equal(gll*,gll*);
int depth(gll*);
gll*create1(char*);//without recursion
static int i=0;


int main()
{
  s=new struct stack;
  s->top=-1;
  char a[50],b[50];
  cout<<"\nenter the string\n";
  cin>>a; 
   cout<<"\nenter string\n";
  cin>>b;
  
  
 
  gll* q=create1(a);
  print(q);
  i=0;
  gll* g=create(b);
  cout<<"\n gll is\n";
  print(g);
  cout<<"\ndepth of gll is\n";
  cout<<depth(q);
  struct gll* p=copy1(g);
  cout<<"\ncopied gll is\n";
  print(p);
  if( equal(q,g) )
    cout<<"\ntwo gll are equal\n";
  else
    cout<<"\ntwo gll are not equal\n";
  return 0;
}
 

gll* create(char* a)       // a(b,c(d,e),f)g
{
  
  gll* t=new gll;
  
  while(a[i]!='\0')
  {
    if( isalnum(a[i]) )
    {
      t->flag=0;
      t->u.c=a[i];
      i++;
      t->nxt=create(a);
      
    }   
    else if( a[i] == '(')
    {
      t->flag=1;
      i++;
      t->u.down=create(a);
      i++;
      t->nxt=create(a);
    }
    else if( a[i]== ')' )
    {
      delete t;
      return NULL;
    }
      return t;
  }
  
}

void print(gll * t)
{
  if(t!=NULL)
  { 
    if(t->flag == 0)
    {
      cout<<t->u.c;
      print(t->nxt);
    }
    else if(t->flag == 1)
    {
      cout<<"(";
      print(t->u.down);
      cout<<")";
      print(t->nxt); 
    }
  }
}


gll* copy(gll* t)
{
  gll* g=new gll;

  if(t!=NULL)
  {
    if(t->flag == 0)
    {
      g->flag=0;
      g->u.c=t->u.c;
      g->nxt=copy(t->nxt);
    }
    else if(t->flag == 1) 
    {
      g->flag=1;
      g->u.down=copy(t->u.down);
      g->nxt=copy(t->nxt);
    }
  }
  else
  { 
    delete t;
  }
  return t;  
}


int equal(gll* t1,gll* t2)
{
  static int e=1;

  if(e == 1 && ( t1!=NULL || t2!=NULL) )
  {

    if( (t1 == NULL && t2!=NULL) || ( t2==NULL && t1!=NULL) )
        e=0;
    else if(t1->flag == 0 && t2->flag == 0)
    {
       if(t1->u.c == t2->u.c)
       { 
          equal(t1->nxt,t2->nxt);
       }
       else
         e=0;
    }
    else if(t1->flag == 1 && t2->flag ==1)
    {
      equal(t1->u.down,t2->u.down); 
      equal(t1->nxt,t2->nxt);
    }
    else
      e=0;
  }
  
  return e;
}


int depth(gll* t)
{
  
  
  if(t==0)
    return 0;
  else
  {
    int depth1=0;
    while(t!=NULL)
    {
      if(t->flag==1)
      {
        int temp=depth(t->u.down);
        if(temp>depth1)
          depth1=temp;
      }
      t=t->nxt;
    }
    return depth1+1;
  }
}


gll* create1(char* a)
{
  int i=0;
  gll* head=NULL;
  gll* p=head;
  while(a[i]!='\0')
  {
    gll* t=new gll;
    if( isalnum(a[i]) )
    {
      t->flag=0;

      t->u.c=a[i];
    //  cout<<t->u.c<<" "<<i<<endl;
      t->nxt=NULL;
      if(i==0)
      {
        head=t;
        p=head;
      }
      
      else if(p!=NULL && p->flag==1 && p->nxt == p)
      {
        p->u.down=t;
        p=t;
      }
      else if(p!=NULL)
      {
        p->nxt=t;
        p=t;
      }
    }
    else if(a[i]=='(')
    {
      
      t->flag=1;
      t->nxt=t; // as a flag
      push(t);
      if(i==0)
      {
        head=t;
        p=head;
      }
      else if(p!=NULL && p->flag==1 && p->nxt == p)
      {
        p->u.down=t;
        p=t;
      }
      else if(p!=NULL)
      {
        p->nxt=t;
        p=t;
      }
     // cout<<"( "<<i<<endl;;
    }
    else if(a[i]==')')
    {
      delete t;
     //  cout<<") "<<i<<endl;;
      p=pop();
      p->nxt=NULL;
    }
    i++;
  }
  return head;
}


gll* copy1(gll* t)
{
  gll* head=NULL,*p;
  if(t->flag==0)
  {
    head=new gll;
    head->flag=0;
    head->u.c=t->u.c;
    head->nxt=NULL;
    p=head;
    t=t->nxt;
  }
  else
  {
    head=new gll;
    head->flag=1;
    push(head);
    head->nxt=head;
    p=head;
    push(t);
    t=t->u.down;
  }
  while(s->top!=-1 || t!=NULL)
  {
    while(t!=NULL)
    {  
      gll* q=new gll;
  
      if(t->flag==0)
      {
        q->flag=0;
        q->u.c=t->u.c;
        q->nxt=NULL;
      
        if(p!=NULL && p->flag==1 && p->nxt == p)
        {
          p->u.down=q;
          p=q;
          t=t->nxt;
        }
        else if(p!=NULL)
        {
          p->nxt=q;
          p=q;
          t=t->nxt;
        }
      }
      else if(t->flag ==1)
      {
        q->flag=1;
        q->nxt=q;
        push(q);
        push(t);
        if(p!=NULL && p->flag==1 && p->nxt == p)
        {
          p->u.down=q;
          p=q;
          t=t->u.down;
        }
        else if(p!=NULL)
        {
          p->nxt=q;
          p=q;
          t=t->u.down;
        }
      }
    }
    if(s->top!=-1)
    {  
      t=pop();
      t=t->nxt;
      p=pop();
      p->nxt=NULL;
    }
  }
  return head;
}



void push(gll* c)
{
  if(s->top==MAX-1)
    cout<<"Stack overflow";
  else
  {
    s->top++;
    s->a[s->top]=c;
  }  
}


gll* pop()
{
  gll* c;
  if(s->top==-1)
    printf("Stack underflow");
  else
    {c=s->a[s->top];
     s->top--;}
 return c;
}
