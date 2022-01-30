#include<stdio.h>
#include<malloc.h>
int main()
{
 
int n,key;
printf("enter no of elements");
scanf("%d",&n);
int *p=(int*)malloc(n*sizeof(int));
printf("\nenter the elements");
for(int i=0;i<n;i++)
{
  scanf("%d",&p[i]);
}

printf("\nenter the key to be searched");
scanf("%d",&key);
int i;
for( i=0;i<n;i++)
{
  if(p[i]==key)
    break;
}

if(i==n)
printf("\nelement not present");
else
printf("\n element is present at %d",i+1);
return 0;
}
