

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50

struct stack
{
	int a[max];
	int top;
}p;
struct stack *s=&p;

int calculate(char c[]);
void push(int x)
{
	if(s->top==max-1)
	{
		printf("Stack overflow:");
	}
	else
	{
		s->top++;
		s->a[s->top]=x;
	}
}
int pop()
{
   int x;
	if(s->top ==-1)
	{
		printf("Stack underflow:");
		return(-1);
	}
	else 
	{
		x= s->a[s->top];
		s->top--;
		return x;	
	}
}
 
int main()
{
	char c[max];
	s->top=-1;
	int result;
 	scanf("%s",c);
	result=calculate(c);
	printf("THE EVALUATEED POSTFIX EXPRESSION IS : %d",result);
        return  0;
}
int calculate(char c[])
{
	int operand1,operand2,i,result,v;
	while(c[i]!='\0')
	{
		if(c[i]=='+')   
		{
		  operand2=pop();
		  operand1=pop();result=operand1+operand2;
		  push(result);
       }
							
		else if( c[i]=='-')
		{
	          operand2=pop();
		  operand1=pop();
                  result=operand1-operand2;
                  push(result);
		}
							
		else if(c[i]=='*')
		{
                   operand2=pop();
    	 	   operand1=pop();
                   result=operand1*operand2;		
		   push(result);
		}
							
		else if(c[i]=='/')
		{
		     operand2=pop();
		     operand1=pop();result=operand1/operand2;
		     push(result);
							
		}
		
		 else
		{
		     printf("\n\tEnter the value of %c" , c[i]);
		     scanf("%d",&v);
		     push(v);
							
      }
i++;
}
	
	return (result);
}

