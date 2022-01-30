#include<iostream>
using namespace std;
//typedef long int li;
int main()
{
int t;
cin>>t;
long int avg[t];
for(int i=0;i<t;i++)
{
 int n;
 cin>>n; 
 long int a[n];
for(int j=0;j<n;j++)
{
 cin>>a[i];
}


long int large=a[0];
//cout<<large<<" ";
int p,c=0;
for(int h=0;h<n;h++)
{
  if(a[h]>=large)
  { 
    //cout<<h<<endl;
    large=a[h];
    p=h;
    //cout<<large<<"    ";
    
  } 
}
//cout<<large<<endl;
a[p]++;
avg[i]=large;
c++;
long int larg2;
do
{

larg2=a[0];
for(int i=0;i<n;i++)
{
  if(a[i]>=larg2)
  {
   larg2=a[i];
   p=i;
  }
}
  a[p]++;
  c++;
}while( ((avg[i]+larg2)/c)>avg[i]);
 //cout<<avg;

}
for(int i=0;i<t;i++)
cout<<avg[i]<<endl;
return 0;
}
#include<iostream>
using namespace std;

void sort(int a[],int b[],int n1,int n2);
int main()
{
int n1=5,n2=7;

int a[n1]={2,4,5,7,9},b[n2]={1,2,3,6,8,34,56};

sort(a,b,n1,n2);
}
int bs(int a[],int key,int l,int u)       
{                                              
int m=(l+u)/2;                        
while(a[m]!=key && u!=l && m!=l && m!=u )                  
{
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
}
if(a[m]>key)  
  return m;
else
  return m+1; 
}
void sort(int a[],int b[],int n1,int n2)
{
static int t[(const int)(n1+n2)];
int g;
static int c=0,x=0,y=0;
while(c<n2)
{
   g=bs(a,b[c++],y,n1-1);
   //cout<<g<<endl;
   for(int i=y; i<g;i++)
   { 
    t[x++]=a[y++];
    //cout<<"f"<<t[x-1]; 
   }
   //cout<<"k";
   t[x++]=b[c-1];
   //cout<<t[x-1]<<endl;
  
}
/*if(c!=n2-1)
{
for(int i=c+1;i<n2;i++)
t[x++]=b[i];
}
else if(y-1!=n1-1)
{
for(int i=x;i<n1-1;i++)
t[x++]=b[i];
}*/
for(int i=0;i<(n1+n2);i++)
{
cout<<t[i]<<" ";
}

}

