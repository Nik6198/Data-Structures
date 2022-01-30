#include<iostream>
using namespace std;
int fib(int*,int,int);

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
  cout<<"enter the key element \n";
  cin>>h;
  h=fib(a,n,h);
  if(h==-1)
    cout<<"no not present";
  else
    cout<<"no present at "<<h+1;
  return 0;
}


int fib(int* a,int n,int key)
{
  //cout<<n<<" "<<key<<"\n";
  int flag=-1;
  int f1=0,f2=1,f3=f1+f2;
  int f[n];
  f[0]=f1; f[1]=f2; f[2]=f3;
  int k=3;
  //cout<<"p="<<f3<<" q="<<f2<<" r="<<f1<<endl;
  while(n >= f3)
  {
    f1=f2;
    f2=f3;
    f3=f1+f2;
   // cout<<f3<<"h"<<endl;
    f[k++]=f3;
  } 
  
  int p=f[k-2];
  int q=f[k-3];
  int r=0;
  if(k-4>0)
   r=f[k-4];

  //cout<<"p="<<p<<" q="<<q<<" r="<<r<<endl;
  int m=n+1 - p-q;
   // cout<<"p="<<p<<" q="<<q<<" r="<<r<<endl;
  if(key>a[p])
    p=p+m;
 
 
  
  while(p!=0 )
  {
    //cout<<"p="<<p<<" q="<<q<<" r="<<r<<" a[p]"<<a[p]<<"\n";
    if(a[p]==key)
    {
      return p;
    }
    else if(a[p]>key)
    {
      if(r == 0)  
      {
        if(a[r]==key)
          return r;
        p=0;
      }
      else
      {
        p=p-r;
        int t=q;
        q=r;
        r=t-q;
      }
    }
    else
    {
      if(q==1)
        p=0;
      else
      {
        p=p+r;
        q=q-r;
        r=r-q;
      }
        
    }
  }
  return flag;
}
