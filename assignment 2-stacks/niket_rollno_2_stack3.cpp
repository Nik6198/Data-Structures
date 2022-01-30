#include<iostream>
#include<stdio.h>
#define MAX 100
#include<string.h>
using namespace std;
struct element
{
    int p;
    char s[MAX];
};
struct stack
{
  struct element a[MAX];
  int top;
}*sp;

void push(struct element c)
{
  if((sp->top)==MAX-1)
    cout<<"Stack overflow";
  else
  {
    (sp->top)++;
    (sp->a[sp->top]).p=c.p;
    strcpy((sp->a[sp->top]).s,c.s);
  }  
}
struct element pop()
{
  struct element c;
  if(sp->top==-1)
    printf("Stack underflow");
  else
    {c.p=(sp->a[sp->top]).p;
     strcpy(c.s,sp->a[sp->top].s);
     sp->top--;}
 return c;
}

int main() {
    stack st;
    sp=&st;
    sp->top=-1;
    int tr;
cin>>tr;
    char str[MAX],s1[MAX],temp[MAX];
    int k,i,g,l,m;
    int c;
    for(int q=0;q<tr;q++)
    {
     cin>>c;
        struct element t;
        switch(c)
        {
            case 1:
                   cin>>s1;
                   strcat(str,s1);
                   t.p=c;
                   strcpy(t.s,s1);
                  
                   push(t);
                   break;
            case 2:cin>>k;
                   m=strlen(str);
                   for( i=m-k,l=0; i<=(m); i++)
                   {
                       temp[l++]=str[i];
                  
                   }
                   temp[l]='\0';
             
                   str[m-k]='\0';
               
                   t.p=c;
                   strcpy(t.s,temp);
                   
                   push(t);
                   break;
            case 3:cin>>k;
                  
                   cout<<str[k-1]<<endl;
                   break;
            case 4:t=pop();
                
                   switch(t.p)
                   {
                       case 1:
                              
                              m=strlen(str)-strlen(t.s);
                              str[m]='\0';
                            
                              break;
                       case 2:strcat(str,t.s);
                             
                              break;
                 
                              
                              
                              
                   }
                   break;
         
                
                      
        }
    }
    return 0;
}
