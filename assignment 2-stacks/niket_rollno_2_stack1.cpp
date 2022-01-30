#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MAX 50
struct stack
{
  char a[MAX];
  int top;
}*s;

void push(char c)
{
  if(s->top==MAX-1)
    cout<<"Stack overflow";
  else
  {
    s->top++;
    s->a[s->top]=c;
  }  
}
char pop()
{
  char c;
  if(s->top==-1)
    printf("Stack underflow");
  else
    {c=s->a[s->top];
     s->top--;}
 return c;
}
void postfix1(char [],char []);
int main()
{
struct stack s1;
s=&s1;
s->top=-1;
char infix[MAX];
scanf("%s",infix);
char postfix[strlen(infix)];
postfix1(infix,postfix);
return 0;
}
int precedence(char c)
{
  if(c=='*' || c=='/')
    return 1;
  else if(c=='+' || c=='-')
    return 0;
  else
    return -1;
}
void postfix1(char infix[], char postfix[]) // a+b/c*d-e*(f-g)
{                                           // a+b/c*d-e*fg-
  int i=0,k=0;                              // a+bc/*d-e*fg-
  while(infix[i]!='\0')                     // a+bcd/*-efg-*
  {                                         // abcd+/*-efg-*
    if(infix[i]>='a' && infix[i]<='z')      // abcdefg-*+/*
      {postfix[k++]=infix[i++];}
      //cout<<postfix[k-1];}
    else if(infix[i]=='(')
       {push(infix[i++]);}
       // cout<<s->a[s->top];}
    else if(infix[i]==')')
    {
      while(s->a[s->top]!='(')
      {// cout<<s->a[s->top];
        postfix[k++]=pop(); 
        //cout<<postfix[k-1];
      }
      pop();
      i++;
    }
   else if(precedence(infix[i])<precedence(s->a[s->top]))
      {
        while(s->top!=-1)
        {
          postfix[k++]=pop();
        }
        push(infix[i++]);
      }
   else if(precedence(infix[i])==precedence(s->a[s->top]))
     {
       postfix[k++]=pop();
       push(infix[i++]);
     }
   else
     {push(infix[i++]);}
    // cout<<s->a[s->top];}
  }

 while(s->top!=-1)
  {postfix[k++]=pop();}
for(int i=0;i<k;i++)
{cout<<postfix[i];}
}
