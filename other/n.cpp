#include<stdio.h>
//#include<iostream>
#include<string.h>
using namespace std;
void push(char stack[10][100],char input[],int *top)
{
    if ((*top)>=10)
    {
        printf("the stack is full");  
    }
    else
    {
        (*top)++;
        strcpy(stack[*top],input);
     
    }
}
void pop(char stack[10][100],int *top)
{
    
    if(*top==-1)
    {
        printf("stack underflow");
    }
    else
    (*top)--;
}
void pair(char input[1000],char stack[10][100],int *top)
{
	char s[15];

	if (strcmp(stack[*top],"<html>")==0)
	{
            strcpy(s,"</html>");
	}
	else 	if (strcmp(stack[*top],"<head>")==0)
	{
		strcpy(s,"</head>");
	}
	else 	if (strcmp(stack[*top],"<body>")==0)
	{
		strcpy(s,"</body>");
	}
	else 	if (strcmp(stack[*top],"<title>")==0)
	{
		strcpy(s,"</title>");
	}
	else 	if (strcmp(stack[*top],"<h1>")==0)
	{
		strcpy(s,"</h1>");
	}
	else 	if (strcmp(stack[*top],"<h2>")==0)
	{
		strcpy(s,"</h2>");
	}
		else 	if (strcmp(stack[*top],"<h3>")==0)
	{
		strcpy(s,"</h3>");
	}
	if (strcmp(input,s)==0)
	{
	     
              pop(stack,top);
	}
	else
	{
                
		printf("the program is not balanced\n");
	}

}

int main ()
{
    char stack[10][100]={"a"};
    char input[1000];
    int ch;
    char c[1000];
    int top=-1;
    do
    {
       
    printf("do you want to enter a line?\n");
    printf("press 1 to enter a line,  press 0 to exit\n");
    scanf("%d",&ch);
    printf("Enter the line\n");
    scanf("%s",&input);
    if(strcmp(input,"<html>")==0||strcmp(input,"<head>")==0||strcmp(input,"<body>")==0||strcmp(input,"<title>")==0||strcmp(input,"<h1>")==0||strcmp(input,"<p>")==0||strcmp(input,"<h2>")==0||strcmp(input,"<h3>")==0)
    {
        push(stack,input,&top);  
        //printf(stack[top]);
    }
    else if(strcmp(input,"</html>")==0||strcmp(input,"</head>")==0||strcmp(input,"</body>")==0||strcmp(input,"</title>")==0||strcmp(input,"</h1>")==0||strcmp(input,"</p>")==0||strcmp(input,"</h2>")==0||strcmp(input,"</h3>")==0)
    {
        pair(input,stack,&top);
    }
  
    } while(ch!=0);
    
        return 0;
}
