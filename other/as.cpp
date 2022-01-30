#include<iostream>
#include<math.h>
using namespace std;
void quad_sort(int a[],int ai[],int j,int n);
void remove(int a[],int aux[][2],int sort[],int j,int n);
int main()
{
  int n;
  n=9;
 // cout<<"Enter the number of elements in the array(strictly n should be perfect square) ";
  //cin>>n;
  int a[n]={12,12,45,18,-7,56,-32,3,99};
  /*int a[n];
  cout<<"Enter the array elements with spaces between them \n";
  for(int i=0;i<n;i++)
  {
    cin>>a[i];                  //45,56,99
  }*/                           //45,56,3
  int j=sqrt(n);                //45,18,3
  int ai[j+1];                  //23,18,3 
  ai[0]=0;                      //12,18,3
  for(int i=1;i<j+1;i++)        //12,-7,3   
  {                             //x,-7,3 
    ai[i]=i*j;                  //x,-7,-32         
  }                             //x,x,-32   
  quad_sort(a,ai,j,n);          //x,x,x                             
  return 0;                  
}                              
void quad_sort(int a[],int ai[],int j,int n)
{

  int aux[j][2];
  int auxcount[j];
  for(int l=0;l<j;l++)
  {
    aux[l][1]=0;
  }
  int sort[j*j];
  for(int i=0;i<j;i++)
  { 
    int large=a[ai[i]];
    int u;
    for(int k=ai[i];k<ai[i+1];k++)
    {
      if(a[k]>large)
      {
        large=a[k];
        u=k;
      }
    }
    a[u]++;
    aux[i][0]=large;
   } 
   for(int i=0;i<n;i++)
   {
    cout<<a[i];                  //45,56,99
  }
   cout<<endl;
   remove(a,aux,sort,j,n);
   cout<<"The sorted array in descending order is\n";
   for(int i=0;i<n;i++)
   {
     cout<<sort[i]<<" ";
   }
   cout<<endl;
}
void remove(int a[],int aux[][2],int sort[],int j,int n)
{
  if(n>0)
  {
    static int k=0; 
    int l;
    int largest=aux[0][0];
    for(int p=0;p<j;p++)
    {
      if(aux[p][0]>=largest)
      {
        largest=aux[p][0];
        l=p;
      }
    }
    
    for(int i=0;i<9;i++)
  {
    cout<<a[i]<<" ";                  //45,56,99
  }
  cout<<endl;
    if(aux[l][1]<j)
    {
      cout<<largest<<" ";
      sort[k++]=largest;
      cout<<++aux[l][1]<<" ";
    }
    else
    {
      aux[l][1]=-3200;
    }
    cout<<l<<" ";
    int larg2=-32000;
    int p;
    for(int g=l*j;g<(j*(l+1));g++)
    {
      if(a[g]>larg2 && a[g]<largest )  
      {  
        larg2=a[g];
        p=g;
      }
    }
   // a[p]++;
    aux[l][0]=larg2;
    cout<<larg2<<endl;
    remove(a,aux,sort,j,--n);
    }  
}

