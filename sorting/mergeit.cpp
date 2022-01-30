#include<iostream>
using namespace std;
void merge_sort(int a[],int up,int down);
void merge(int a[],int up,int down,int mid);
int main()
{ 
int n=9;
//int a[n]={45,23,67,35,76,2,90,65,34};
int a[n];
cout<<"\nenter no of elements";
cin>>n;
cout<<"\nenter elements\n";
for(int i=0;i<n;i++)
{
 cin>>a[i];
}
int up=0;
int down=n-1;
merge_sort(a,up,down); 
cout<<"Final : ";
for(int i=0;i<n;i++)
{
 cout<<a[i]<<" ";
}
return 0;
}
void merge_sort(int a[],int up,int down)
{
  for(int m=1;m<=down;m*=2)
  {
    for(int i=up;i<=down;i+=2*m)
    {
      int from=i;
      int mid=i+m-1;
      int to;
      if((i+2*m-1)<down)
        to=(i+2*m-1);
      else
        to=down;
      //cout<<"from "<<from<<"mid "<<mid<<"to "<<to<<endl;;
      merge(a,from,to,mid);
    }
  }
  
}
void merge(int a[],int up,int down,int mid)
{
 int i=up,j=mid+1;
 int temp[(down-up+1)];
 int k=0;
 
 while(i<=mid && j<=down)
  {
    if(a[i]<a[j])
     { 
       temp[k++]=a[i++];
     } 
    else
     { 
       temp[k++]=a[j++];
     }   
  }
 while(i<=mid)
  { 
	temp[k++]=a[i++];
  }
 while(j<=down)
  {
    temp[k++]=a[j++];
  }

 for(int g=0;g<k;g++)
 { 
   a[g+up]=temp[g];
   
 }

 
}
