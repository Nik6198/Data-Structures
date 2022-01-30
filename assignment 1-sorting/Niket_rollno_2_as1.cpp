/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*

Name-Niket Doke
rollno-2


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include<iostream>
#include<math.h>
using namespace std;
void quad_sort(int a[],int ai[],int j,int n);
void remove(int a[],int aux[][2],int sort[],int j,int n);
int main()
{
  int n;
  n=9;
  cout<<"Enter the number of elements in the array(strictly n should be perfect square) ";
  cin>>n;
  //int a[n]={23,12,45,18,-7,56,-32,3,99};
  int a[n];
  cout<<"Enter the array elements with spaces between them \n";
  for(int i=0;i<n;i++)
  {
    cin>>a[i];                  
  }                           
  int j=sqrt(n);                
  int ai[j+1];                   
  ai[0]=0;                      
  for(int i=1;i<j+1;i++)          
  {                            
    ai[i]=i*j;                         
  }                              
  quad_sort(a,ai,j,n);                                     
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
    int u=ai[i];
    for(int k=ai[i];k<ai[i+1];k++)
    {
      if(a[k]>large)
      {
        large=a[k];
        u=k;
      }
    }
    //cout<<large<<" ";
   //if(a[u]>0)
    a[u]++;
  // else
   // a[u]--;
    aux[i][0]=large;
   } 
  //for(int i=0;i<n;i++)
   //{cout<<a[i]<<" ";}cout<<endl;
  
   remove(a,aux,sort,j,n);
   cout<<"\nThe sorted array is\n";
   for(int i=n-1;i>=0;i--)
   {
     cout<<sort[i]<<" ";
   }
   cout<<endl;
}
void remove(int a[],int aux[][2],int sort[],int j,int n)
{
  //if(n>0)
  while(n>0)
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
  // cout<<largest<<" "<<l<<endl;
  //  

    if(aux[l][1]<j)
    {
      
      sort[k++]=largest;
     
    }
    else
    {
      aux[l][1]=-3200;
    }
    //if(largest>0)
    largest++;
    //else
    //largest--;
    int larg2=-32000;
    int p;
    for(int g=l*j;g<(j*(l+1));g++)
    {
      if(a[g]>larg2 && a[g]<largest )  
      {  
        larg2=a[g];
        p=g;
      }
     // cout<<a[p]<<" p";
      
    }
    a[p]++;
   // cout<<larg2<<endl;
    aux[l][0]=larg2;
  /*  for(int i=0;i<j;i++)
    {cout<<aux[i][0]<<" ";}cout<<endl;
     for(int i=0;i<n;i++)
   {cout<<a[i]<<" ";}cout<<endl;*/
  
    //remove(a,aux,sort,j,--n);
    --n;
    }  
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                             OUTPUT

Enter the number of elements in the array(strictly n should be perfect square) 
9
Enter the array elements with spaces between them 
-4 -9 -3 0 3 1 6 4 7

The sorted array is
-9 -4 -3 0 1 3 4 6 7 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
