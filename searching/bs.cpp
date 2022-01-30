#include<iostream>
using namespace std;
int main()
{
int n;
cout<<"enter no of elements\n";
cin>>n;  //   0  1  2  3  4  5
cout<<"enter the elements\n";
int a[n];//a={5, 15,24,34,40,56}
for(int i=0;i<n;i++)
{
 cin>>a[i];
}
int l=0,u=(n-1),m=(l+u)/2;
int no;
cout<<"enter the element to be searched\n";
cin>>no;
while(a[m]!=no && m!=l && m!=u)
{
  if(no>a[m])
    {
      l=m;
      m=(u+l)/2;
    }
  else
   {
     u=m;
     m=(u+l)/2;
   }
}
if(a[m]==no)
{
cout<<"no is present at "<<m+1;
}
else
cout<<"no is not present";

return 0;






}
