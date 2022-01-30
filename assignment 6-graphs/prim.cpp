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

graph** create(int);
void prim(graph*,graph**,int);


int main()
{
  int n;
  cout<<"\nenter the no of nodes in graph\n";
  cin>>n;
  graph** g=create(n);
  
  cout<<"\n\nusing prim algorithm \n";
  prim(g[0],g,n);
  
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


void prim(graph* p,graph** t,int n)
{
  int* dist=new int[n];
  graph* temp=t[p->data-1];
  int G[n][n]={0};

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
    
  } 
  

  int *parent=new int[n];
  for(int i=0;i<n;i++)
    parent[i]=i+1;
  
  for(int i=0;i<n;i++)
  {
    dist[i]=G[p->data-1][i];
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

  cout<<"spanning tree is \n";
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
      if(visited[i]!=1 && dist[i]>G[v][i])
      {
        dist[i]=G[v][i];
        parent[i]=v+1;
      }
    }

    cout<<v+1<<","<<parent[v]<<" ";
  }
  cout<<endl;
  min=0;
  for(int i=0;i<n;i++)
  {  
   min+=dist[i];
   //cout<<dist[i]<<" ";
  }
  cout<<"minimum cost is\n"<<min<<endl;
}
