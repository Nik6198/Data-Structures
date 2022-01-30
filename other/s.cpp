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
  printf("%d\n",top);
  
  push(5);
  printf("%d\n",top);
  push(5);
  printf("%d\n",top);
  push(4);
    printf("%d\n",top);
  return 0;
}

//full
int full(int max)
{
 if(top==max-1)
 { return 1; }
 else 
 {return 0; }
 
}

//push
void push(int max)
{
int x;
//printf("K");
top++;
  if(full(max))
  { printf("stack is full");
    }
  else 
  {
  //printf("l");
  scanf("%d",&x);
  item[top]=x;
  printf("%d",item[top]);
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

