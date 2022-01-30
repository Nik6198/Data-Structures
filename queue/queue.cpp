#include<iostream>
#include<stdio.h>
#define MAX 5
using namespace std;
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
int main()
{
struct queue q1;
q=&q1;
q->front=q->rear=-1;
cout<<" 5 is enqueued\n";
enqueue(5);
cout<<" 10 is enqueued\n";
enqueue(10);
cout<<"dequeued elememt is\n";
cout<<dequeue()<<endl;
cout<<"dequeued elememt is\n";
cout<<dequeue()<<endl;
return 0;
}
