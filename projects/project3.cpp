#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<cstring>
#include<string>

using namespace std;
#define MAX 50


struct node
{
  string str;
  struct node* nxt;
};


typedef struct node node;

struct stack
{
  node* head;
  int top;
}*s1,*s2,*s3;


typedef stack stack;


// stack push operation //

void push(stack* s,string c)
{
  s->top++;
  node* temp=new node();
  temp->str=c;
  temp->nxt=NULL;
  
  if(s->head==NULL)
    s->head=temp;
  else
  {
    temp->nxt=s->head;
    s->head=temp;
  }
}


// backward button //

string backward()
{
  if(s1->top!=-1)
  {
    string c=" ";
    s1->top--;
    node* temp=s1->head;
    s1->head=s1->head->nxt;

    if(s1->head!=NULL)
      c=s1->head->str;
  
    s2->top++;
    if(s2->head==NULL)
      s2->head=temp;
    else
    {
      temp->nxt=s2->head;
      s2->head=temp;
    }
    //cout<<"ll"<<c<<endl;
    return c;
  } 
  else
    return " "; 
}


// forward button //

string forward()
{ 
  if(s2->top!=-1)
  {
    string c=" ";
    s2->top--;
    if(s2->head!=NULL)
    {
      c=s2->head->str;
      node* temp=s2->head;
      s2->head=s2->head->nxt;
     // s2->top--;
  
    s1->top++;
    if(s1->head==NULL)
      s1->head=temp;
    else
    {
      temp->nxt=s1->head;
      s1->head=temp;
    }
    }
    return c;
  }    
  else
   return NULL; 
}


// to empty the stack //

void empty(stack* s)
{
  node* temp=NULL;
  while(s->top!=-1)
  {
    s->top--;
    temp=s2->head;
    s->head=s->head->nxt;
    delete temp;
  }
}


// printing the elements in stack //

void print(stack* s)
{
  node* t=s->head;
 
  while(t!=NULL)
  {
    cout<<t->str<<endl;
    t=t->nxt;
  }
}


// entry point function //
int main()
{
  // initialising stacks //
  stack st1,st2,st3;
  s1=&st1;
  s2=&st2;
  s3=&st3;
  s1->top=s2->top=s3->top=-1;
  s1->head=s2->head=s3->head=NULL;

  // defining counters and flags //
  int ch,i,j,k; 
  int flag1=1,flag2=1;

  // validation strings  // 
  char* check1=(char*)"www.";
  char* check2=(char*)"moc.";
  char*check3=(char*)"gro.";
  char*check4=(char*)"ni.";

  // buffer strings ??
  string str1=" ",f,str2=" ";
  
  while(ch!=5)
  {  
    cout<<"\n\nenter the number to perform corresponding operation\n1.enter url\t2.backward\t3.forward\t4.history\t5.exit\n";
    cin>>ch;
    cout<<"\n";
    switch(ch)
    {
      case 1:flag1=1;flag2=1;
             while(flag1==1 || flag2==1)
             {     
               flag1=1;flag2=1;
               cin>>str1;
               string :: iterator it;
               string :: reverse_iterator it1,it2,it3;
               for(it=str1.begin(),i=0;i<4;i++)
               {
                  if(*it!=check1[i])       
                     break;
                   it++;
               }
               if(i==4)
               {  
                 flag1=0;
               }

                for(it1=str1.rbegin(),i=0;i<4;i++)
               {
                  if(*it1!=check2[i])       
                     break;
                   it1++;
               }
                for(it2=str1.rbegin(),j=0;j<4;j++)
               {
                  if(*it2!=check3[j])       
                     break;
                   it2++;
               }
                for(it3=str1.rbegin(),k=0;k<3;k++)
               {
                  if(*it3!=check4[k])       
                     break;
                   it3++;
               }
               
               if( flag1 == 0 && (i == 4 || j == 4 || k == 3) )
               {
                 flag2=0;
                 push(s1,str1);
                 push(s3,str1);  
                 empty(s2); 
                 f=str1;
               }
               else
                 cout<<"enter valid url\n";
              // cout<<i<<j<<k;
             }
             break;
      case 2: 
             if(s1->top==0 && s1->head->str==f)
               cout<<f<<endl;
             else
             {
                f=backward();
                push(s3,f);
               cout<<f<<endl;
             }
             break;
      case 3:if(s2->top==-1)
               cout<<str1<<endl;
             else 
             {
               str2=forward();
               cout<<str2<<endl;
               push(s3,str2);
             }
             break;
      case 4:cout<<str1<<"\nHistory\n\n";
             print(s3);
             break;
      case 5:break;
      
    }
  }

  return 0;
}



