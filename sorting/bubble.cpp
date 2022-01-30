#include<stdio.h>
#include<malloc.h>
void sort(int*,int);

int main()
{

int n;
printf("enter no of elements");
scanf("%d",&n);
int *p=(int*)malloc(n*sizeof(int));
printf("\nenter the elements");
for(int i=0;i<n;i++)
{
  scanf("%d",&p[i]);
}
sort(p,n);
printf("\nafter sorting the elements are");
for(int i=0;i<n;i++)
{
  printf("%d ",p[i]);
}


return 0;
}

void sort(int *a,int n)
{
  int flag;
  for(int i=0;i<n;i++)
  {
    flag = 1;
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
	flag = 0;
      }
    }
    if(flag == 1) break;
  }
}

