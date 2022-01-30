#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<cstring>
#include<string>

using namespace std;
#define MAX 50

typedef struct position
{
  int x;
  int y;
  int dir;
}position;


typedef struct stack
{
  position p[MAX];
  int top;
}stack;

stack *s;
stack *path;

void push(position ,stack *);
position pop(stack *);
void maze(int,int** );


int main()
{
  s=new stack;
  path=new stack;
  s->top=path->top=-1;
  int n;
  cout<<"\nenter the maze size\n";
  cin>>n;
  int** a=new int*[n+2];
  for(int i=0;i<n+2;i++)
  {
    a[i]=new int[n+2];
  }
  cout<<"\nenter the maze\n";
  for(int i=0;i<n+2;i++)
  { 
    for(int j=0;j<n+2;j++)
    {
      cin>>a[i][j];
    }
  }
  
  maze(n,a);
  

  return 0;
}


void maze(int n,int** a)
{
  position t;
  t.x=1;
  t.y=1;
  t.dir=0;
  push(t,s);
  push(t,path);
  

  for(int i=0;i<n+2;i++)
  { 
    for(int j=0;j<n+2;j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  int dir[8][2];
  dir[0][0]=0; dir[0][1]=-1;
  dir[1][0]=1; dir[1][1]=-1;
  dir[2][0]=1; dir[2][1]=0;
  dir[3][0]=1; dir[3][1]=1;
  dir[4][0]=0; dir[4][1]=1;
  dir[5][0]=-1;dir[5][1]=1;
  dir[6][0]=-1;dir[6][1]=0;
  dir[7][0]=-1;dir[7][1]=-1;

  int found=0;
  int v[n+2][n+2];
  for(int i=0;i<n+2;i++)
  { 
    for(int j=0;j<n+2;j++)
    {
      v[i][j]=0;
    }
  }
  v[1][1]=1;

  while(s->top!=-1 && !found)
  {
    t=pop(s);
   /* cout<<"flags ";
    cout<<(path->p[path->top].x != t.x)<<" ";
    cout<<(path->p[path->top].y != t.y)<<" ";
    cout<<(path->p[path->top].dir != t.dir)<<" \n";*/
   // while( (path->p[path->top].x != t.x) &&  (path->p[path->top].y != t.y) && (path->p[path->top].dir != t.dir) )
    {
     // cout<<"j";
      pop(path);
    }
    int d=t.dir;
    
    while(d<8)
    {
     // cout<<"t.x="<<t.x<<" t.y="<<t.y<<" d="<<d<<"\n";
      int nx=t.x+dir[d][1];
      int ny=t.y+dir[d][0];

     // cout<<nx<<" "<<ny<<"\n";
      
      if( nx == n && ny == n )
      {
         t.x=nx;
        t.y=ny;
        push(t,s);
        push(t,path);
        found =1;
       // cout<<"1\n";
        break;
      }
  
      else if( a[nx][ny] == 0 && !v[nx][ny] )
      {
        t.x=nx;
        t.y=ny;
        t.dir=++d;
        v[t.x][t.y]=1;
        push(t,s);
        push(t,path);
        // cout<<"2\n";
        d=0;
      }
      else
      {
        d++;d++;
         //cout<<"3\n";
      }
    }
   
  }
  a[1][1]=2;
  while(path->top!=-1)
  {
    position y=pop(path);
    a[y.x][y.y]=2;
  }
  
  for(int i=0;i<n+2;i++)
  { 
    for(int j=0;j<n+2;j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  
}







void push(position c,stack *s)
{
  if(s->top==MAX-1)
    cout<<"Stack overflow";
  else
  {
    s->top++;
    s->p[s->top]=c;
  }  
}


position pop(stack *s)
{
  position c;
  if(s->top==-1)
    printf("Stack underflow");
  else
  {
    c=s->p[s->top];
    s->top--;
  }
  return c;
}
