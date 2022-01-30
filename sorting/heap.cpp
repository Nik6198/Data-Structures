qxc

#include<iostream>
using namespace std;
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
cout<<"sorted array elements are:";
for(i=1;i<=n;i++)
{
v=n;
//create min heap
while(v!=0)
{
i=v/2;
if(a[i]>a[v])
{
temp=a[i];
a[i]=a[v];
a[v]=temp;
}
v--;
}
//swap root with last element
temp=a[0];
a[0]=a[n];
a[n]=temp;
cout<<a[n]<<"  ";
n--;
}
return 0;
}


