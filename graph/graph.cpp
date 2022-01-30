#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define MAX 50


struct graph
{
  int data;
  int cost;
  struct graph* nxt;
};

typedef struct graph graph;


struct stack
{
  graph* a[MAX];
  int top;
}*s;


struct queue
{
  graph* d[MAX];
  int front;
  int rear;
}*q;


void push(graph*);
graph* pop();
void enqueue(graph*);
graph* dequeue();
int isEmpty();
int dist1(graph**,int,int);
graph** create(int);
void dfs(graph**,int);
void bfs(graph**,int);
int* dijkstra(graph*,graph**,int);
void prim(graph*,graph**,int);
void kruckal(graph*,graph**,int);

int main()
{
  s=new struct stack;
  s->top=-1;
  q=new struct queue;
  q->front=q->rear=-1;
  int n;
  cout<<"\nenter the no of nodes in graph\n";
  cin>>n;
  graph** g=create(n);
  cout<<"\ndfs is\n"; 
  dfs(g,n);
  cout<<"\nbfs is\n";
  bfs(g,n);cout<<endl;
  cout<<"shortest path using dijkstra for 1 is \n";
  int* dist=dijkstra(g[0],g,n);
  for(int i=0;i<n;i++)
   cout<<dist[i]<<" ";
  cout<<endl;
  cout<<"spanning tree and min cost using prim is\n";
  prim(g[0],g,n);
  cout<<endl;
  cout<<"spanning tree and min cost using kruckal is\n";
  kruckal(g[0],g,n);
  cout<<"\n"<<dist1(g,1,2)<<" "<<dist1(g,4,7)<<" "<<dist1(g,4,5);
  return 0;
}


graph** create(int n)
{
  int m;
  graph** g=new graph*[n];
  for(int i=0;i<n;i++)
  {
    g[i]=new graph;
    cout<<"enter the node\n";
    cin>>g[i]->data;
    g[i]->cost=0;
    g[i]->nxt=NULL;
    cout<<"enter no of adjacents nodes of "<<g[i]->data<<endl;
    cin>>m;
    graph* t=g[i];
    for(int j=0;j<m;j++)
    {
      graph* temp=new graph;
      cout<<"enter adjacent node\n";
      cin>>temp->data;
      cout<<"enter the cost\n";
      cin>>temp->cost;
      //temp->cost=0;
      temp->nxt=NULL;
      t->nxt=temp;
      t=temp;
    }
  }
  return g;
}


void dfs(graph** t,int n)
{
  graph* temp=NULL;
  int* visited=new int[n];
  for(int i=0;i<n;i++)
  {
    visited[i]=0;
  }
  push(t[0]);
  while(s->top!=-1)
  {
    temp=pop();
    if(visited[temp->data-1]!=1)
    cout<<temp->data;
    visited[temp->data-1]=1;
  
    for(temp=t[temp->data-1];temp!=NULL;temp=temp->nxt)
    {
      if(visited[temp->data-1]!=1)
        push(temp);
    }
  }

}


void bfs(graph** t,int n)
{
  graph* temp=NULL;
  int* visited=new int[n];
  for(int i=0;i<n;i++)
  {
    visited[i]=0;
  }
  enqueue(t[0]);
  while(!isEmpty())
  {
    temp=dequeue();
    if(visited[temp->data-1]!=1)
    cout<<temp->data;
    visited[temp->data-1]=1;
  
    for(temp=t[temp->data-1];temp!=NULL;temp=temp->nxt)
    {
      if(visited[temp->data-1]!=1)
        enqueue(temp); 
    }
  }

}


int* dijkstra(graph* p,graph** t,int n)
{
  int* dist=new int[n];
  
  for(int i=0;i<n;i++)
    dist[i]=0;
  //dist[p->data-1]=0;
  graph* temp=t[p->data-1];
 /* int G[n][n];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      G[i][j]=0;
    }
  }
  
  for(int j=0;j<n;j++)
  {
    for(temp=t[j];temp!=NULL;temp=temp->nxt)
    {
      G[j][temp->data-1]=temp->cost;
    }
    for(int i=0;i<n;i++)
    {
      if(G[j][i]==0 && i!=j)
        G[j][i]=999;
    }
  } */
  
  for(temp=t[p->data-1];temp!=NULL;temp=temp->nxt)
  {
    dist[temp->data-1]=temp->cost;
  }

  for(int i=0;i<n;i++)
  {
    if(dist[i]==0 && i!=(p->data-1) )
      dist[i]=999;
  }
  
  int* visited=new int[n];
  for(int i=0;i<n;i++)
  {
    visited[i]=0;
  }
  visited[p->data-1]=1;

  int v;
  
  for(int j=0;j<n-1;j++)
  {
    v=9999;
    for(int i=0;i<n;i++)
    {
      if(visited[i]!=1 && dist[i]<v)
         v=i;
    }
    
    visited[v]=1;
    for(int i=0;i<n;i++)
    {
      if(visited[i]!=1)
      {
        if(dist[i]>dist[v]+dist1(t,v+1,i+1) )
          dist[i]=dist[v]+dist1(t,v+1,i+1); 
      }
    }
    
    
    
  }
  return dist;
 
}


void prim(graph* p,graph** t,int n)
{
  int* dist=new int[n];
  for(int i=0;i<n;i++)
    dist[i]=0;
  graph* temp=t[p->data-1];
  /*int G[n][n]={0};

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      G[i][j]=0;
    }
  }
  for(int j=0;j<n;j++)
  {
    
    for(temp=t[j];temp!=NULL;temp=temp->nxt)
    {
      G[j][temp->data-1]=temp->cost;
    }
    for(int i=0;i<n;i++)
    {
      if(G[j][i]==0 && i!=j)
        G[j][i]=999;
    }
    
  }*/ 
  

  int *parent=new int[n];
  for(int i=0;i<n;i++)
    parent[i]=i+1;

  for(temp=t[p->data-1];temp!=NULL;temp=temp->nxt)
  {
    dist[temp->data-1]=temp->cost;
  }

  for(int i=0;i<n;i++)
  {
    if(dist[i]==0 && i!=(p->data-1) )
      dist[i]=999;
  }
  
  for(int i=0;i<n;i++)
  {
    //dist[i]=G[p->data-1][i];
    if(dist[i]!=999)
      parent[i]=1;
  }
  


  int* visited=new int[n];
  for(int i=0;i<n;i++)
  {
    visited[i]=0;
  }
  visited[p->data-1]=1;

  int v,min=0;

  cout<<"spanning tree \n";
  for(int j=0;j<n-1;j++)
  { 
    min=999;
    for(int i=0;i<n;i++)
    {
      if(visited[i]!=1 && dist[i]<min)
      {
        min=dist[i];
        v=i;
      }
    }
    visited[v]=1;
    
    for(int i=0;i<n;i++)
    {
      if(visited[i]!=1 && dist[i]>dist1(t,v+1,i+1) )
      {
        dist[i]=dist1(t,v+1,i+1);
        parent[i]=v+1;
      }
    }

  //cout<<endl;
    cout<<v+1<<","<<parent[v]<<" ";
  }
  cout<<endl;
  min=0;
  for(int i=0;i<n;i++)
  {  
   min+=dist[i];
   //cout<<dist[i]<<" ";
  }
  cout<<"minimum cost\n"<<min;
}


void kruckal(graph* p,graph** t,int n)
{
  /*int G[n][n]={0};

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      G[i][j]=0;
    }
  }
  for(int j=0;j<n;j++)
  {
    
    for(graph* temp=t[j];temp!=NULL;temp=temp->nxt)
    {
      G[j][temp->data-1]=temp->cost;
    }
    for(int i=0;i<n;i++)
    {
      if(G[j][i]==0 && i!=j)
        G[j][i]=999;
    }
    
  }*/

  
  int m=0; 
  /*for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
       if(G[i][j]!=0 && G[i][j]!=999) 
         m++;
    }
  }*/

  for(int i=0;i<n;i++)
  {
    graph* temp=t[i];
    for(temp=temp->nxt;temp!=NULL;temp=temp->nxt)
      m++;
  }

  m/=2;
   //cout<<m<<endl;
  int e[m][3];
 /* for(int i=0, k=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
      if(G[i][j]!=0 && G[i][j]!=999)
      {
        e[k][0]=i;
        e[k][1]=j;
        e[k][2]=G[i][j];
        k++;
      }
    }
  }*/
 int k=0;
 for(int i=0;i<n;i++)
  {
    graph* temp=t[i];
    for(graph* p=temp->nxt;p!=NULL;p=p->nxt)
    {
      e[k][0]=temp->data;
      e[k][1]=p->data;
      e[k][2]=p->cost;
      k++;
    }
  }
  
  for(int i=0;i<m-1;i++)
  {
    for(int j=0;j<m-i-1;j++)
    {
      if(e[j][2] > e[j+1][2])
      {
        int temp[1][3];
        temp[0][0]=e[j][0];
        temp[0][1]=e[j][1];
        temp[0][2]=e[j][2];
        e[j][0]=e[j+1][0];
        e[j][1]=e[j+1][1];
        e[j][2]=e[j+1][2];
        e[j+1][0]=temp[0][0];
        e[j+1][1]=temp[0][1];
        e[j+1][2]=temp[0][2];
      }
    }
  }
 
 /* for(int i=0;i<m;i++)
  {
    cout<<e[i][0]+1<<" "<<e[i][1]+1<<" "<<e[i][2]<<endl;
  }*/
  
  int* member=new int[n];
  int min=0;
  for(int i=0;i<n;i++)
    member[i]=i+1;
  cout<<"spanning tree \n";
  for(int i=0;i<m;i++)
  {
    int u=member[e[i][0]];
    int v=member[e[i][1]];
    if(u!=v)
    {
      cout<<e[i][0]+1<<","<<e[i][1]+1<<" ";
      min+=e[i][2];
     // cout<<"min"<<min<<" "<<e[i][2]<<endl;
      for(int j=0;j<n;j++)
      {
        if(member[j]==u)
          member[j]=v;
      }
      //for(int i=0;i<n;i++)
        //cout<<member[i]<<" ";cout<<endl;
    }
  }
  cout<<endl<<"minimum cost\n"<<min; 

}
void enqueue(graph* a)
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


graph* dequeue()
{
  graph* a=NULL;
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


int isEmpty()
{
    if(q->front == -1 || q->front>q->rear) return 1;
    return 0;
}


void push(graph* c)
{
  if(s->top==MAX-1)
    cout<<"Stack overflow";
  else
  {
    s->top++;
    s->a[s->top]=c;
  }  
}


graph* pop()
{
  graph* c;
  if(s->top==-1)
    printf("Stack underflow");
  else
  {
    c=s->a[s->top];
    s->top--;
  }
  return c;
}


int dist1(graph** g,int s,int d)
{
  int distance=999;

  for(graph* t=g[s-1];t!=NULL;t=t->nxt)
  {
    if(t->data == d)
    {
      distance=t->cost;
      break;
    }
  }
  return distance;
  
}


/*for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<G[i][j]<<"      ";
    }cout<<endl;
  }*/ 
