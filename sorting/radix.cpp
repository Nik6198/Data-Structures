#include<iostream>
using namespace std;
void radix(int*,int );

int main()
{

  int n;
  int v,temp,i;
  cout<<"How many elements you want in array:";
  cin>>n;
  int a[n];
  cout<<"Enter array elements:";
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  int h;
  cout<<"sorted array elements are:";
  radix(a,n);
  cout<<(-6)%5;
  return 0;
}


void radix(int a[],int n)
{
  
  int b[n];
  int max=a[0];
  for(int i=1;i<n;i++)
  { 
    if(max<a[i])
      max=a[i];
  }

  int e=1;
  while(max/e>0)
  {
    int count[10];
 
    for(int i=0;i<10;i++)
      count[i]=0;

    for(int i=0;i<n;i++)
    {
      if(a[i]>=0)
      count[ (a[i]/e) % 10 ]++;
      else
      count[ ((-a[i])/e) % 10 ]++;
    }
     
    for(int i=0;i<10;i++)
      cout<<count[i];
    cout<<endl;
    for(int i=1;i<10;i++)
    {
      count[i]= count[i]+ count[i-1];
    }
    
    for(int i=0;i<10;i++)
      cout<<count[i];
    cout<<endl;
    for(int i=n-1;i>=0;i--)
    {
      if(a[i]>=0)
      {
        b[ count[ (a[i]/e) % 10 ] -1 ]=a[i];
        count[ (a[i]/e) % 10 ]--;
      }
      else
      {
        b[ count[ ((-a[i])/e) % 10 ] -1 ]=a[i];
        count[ ((-a[i])/e) % 10 ]--;
      }
    }
    
    for(int i=0;i<n;i++)
    {
      a[i]=b[i];
      cout<<a[i]<<" ";
    }
   e*=10;
  }
}

