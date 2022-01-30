#include<iostream>
#include<stdio.h>
using namespace std;
void quick_sort(int a[],int low,int up);
int partition(int a[],int low,int up);
int main()
{
int n;
n=6;
//int a[6]={45,23,7,0,34,100};
int a[n];
cout<<"\nenter no of elements";
cin>>n;
cout<<"\nenter elements\n";
for(int i=0;i<n;i++)
{
 cin>>a[i];
}
int low=0,up=n-1;
quick_sort(a,low,up);
 for(int i=low;i<=up;i++)
  {
    cout<<a[i]<<" ";
  }

return 0;
}
int partition(int a[],int low,int up)
{ 
  int pivot=low;
  int i=pivot+1;
  int j=up;

  while(i<=j)
  { 
  //cout<<"pivot "<<a[pivot]<<"i "<<a[i]<<"j ="<<a[j]<<endl; 
    while(a[pivot]>=a[i] && i<=up)
      i++;
    while(a[pivot]<a[j] )
      j--; 
    if(i<j)
    {
      int temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    //  cout<<a[i]<<" "<<a[j];
    } 

   }
  
  int temp=a[pivot];
  a[pivot]=a[j];
  a[j]=temp;

 
//cout<<"final pivot "<<j<<endl;;
  return j;
  
}
void quick_sort(int a[],int low,int up)
{ 
  if(low<up)
{
  int j=partition(a,low,up);
  quick_sort(a,low,j-1);
  quick_sort(a,j+1,up); 
}
}
