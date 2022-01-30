#include<iostream>
using namespace std;
void heap(int*,int );

int main()
{

  int n;
  int v,temp,i;
  cout<<"How many elements you want in array:";
  cin>>n;
  int a[n+1];
  cout<<"Enter array elements:";
  for(i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  int h;
  cout<<"sorted array elements are:";
  heap(a,n);
  return 0;
}


void heap(int* a,int n)
{
  while(n!=0) 
  {
    int i=n/2;
    while(i!=0)
    {
      if( 2*i+1<=n  &&  a[2*i] > a[2*i+1] )
      {
        if(a[i]>a[2*i+1])
        {
          int temp=a[i];
          a[i]=a[2*i+1];
          a[2*i+1]=temp;
        } 
      }
      else if(2*i <=n  )
      {
        if(a[i]>a[2*i])
        {
          int temp=a[i];
          a[i]=a[2*i];
          a[2*i]=temp;
        }
      }
      i--;
    }
    int temp=a[1];
    a[1]=a[n];
    a[n]=temp;
    cout<<a[n]<<"  ";
    n--; 
  }
}
