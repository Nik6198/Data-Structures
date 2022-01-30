#include<stdio.h>

int full(int );
void push(int );
int empty();
int pop();

char item[100];
int top=-1;

int main()
{
  push(4);
  printf("%d\n",pop());
  push(2);
  printf("%d\n",pop());
  push(1);
  printf("%d\n",pop());
  push(5);
  printf("%d\n",pop());
  return 0;
}

//full
int full()
{
 if(top==100-1)
 { return 1; }
 else 
 {return 0; }
 
}

//push
void push(int x)
{

//printf("K");
top++;
  if(full())
  { printf("stack is full");
    }
  else 
  {
  //printf("l");
 // scanf("%d",&x);
  item[top]=x;
  //printf("%d",item[top]);
  }  
}


//empty
int empty()
{
 if(top==-1)
  { return 1; }
  else {return 0; }
};
//pop
int pop()
{int x;

 if(empty()==1)
 { printf("stack is empty");
  }
 else
 { x=item[top];
 top--;
 return x;}

}

