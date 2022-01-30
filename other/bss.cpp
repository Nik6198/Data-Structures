#include<iostream>
using namespace std;
void sort(int a[],int b[],int n1,int n2);
int main()
{
int n1,n2;
cout<<"Enter number of elements in first array\n";
cin>>n1;
int a[n1],b[n2];
cout<<"Enter the first array elements in ascending order\n";
for(int i=0;i<n1;i++)
{
  cin>>a[i];
}
cout<<"Enter number of elements in second array\n";
cin>>n2;
cout<<"Enter the second array elements in ascending order\n";
for(int i=0;i<n2;i++)
{
  cin>>b[i];
}
sort(a,b,n1,n2);
return 0;
}
int bs(int a[],int key,int l,int u)       
{                                              
int m=(l+u)/2;                        
while( (a[m]!=key) && (u!=l) && (m!=l) && (m!=u) )                  
{
cout<<"q"<<m;
  if(key>a[m])
    {
      l=m+1;
      m=(u+l)/2;
    }
  else
   {
     u=m-1;
     m=(u+l)/2;
   }
cout<<"q"<<endl;
}
cout<<m;
if(a[m]<key)
{
   cout<<"p";  
  return m+1;
}
else
{
  cout<<"l";
  return m;
} 
}
void sort(int a[],int b[],int n1,int n2)
{
int t[(n1+n2)];
int c=0,x=0,y=0,g;
while(c<n2)
{
   g=bs(a,b[c++],y,n1-1);
   cout<<g<<endl;
   for(int i=y; i<g;i++)
   { 
    t[x++]=a[y++];
    cout<<"k"<<t[x-1];
   }
   t[x++]=b[c-1];
   cout<<"j"<<t[x-1]<<endl;
}
cout<<"The sorted array of the above two arrays is\n";
for(int i=0;i<(n1+n2);i++)
{
cout<<t[i]<<" ";
}
}




 




