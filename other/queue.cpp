#include<iostream>
#include<stdio.h>
#define MAX 5
using namespace std;
void merge_sort(int a[],int up,int down);
void merge(int a[],int up,int down,int mid);
struct queue
{
int d[MAX];
int front;
int rear;
}*q;

void enqueue(int a)
{
if(q->rear==MAX-1)
  cout<<"queue is full";
else if(q->front ==-1 && q->rear == -1)
{
  q->front++;
  q->rear++;
  q->d[q->rear]=a;
}
else
{
  q->rear++;
  q->d[q->rear]=a;
}
}

int dequeue()
{
int a=-1;
if( q->front > q->rear || q->front==q->rear==-1 )
  cout<<"queue is empty";
else if(q->front == 0 && q->rear ==0)
{
  a=q->d[q->front];
  q->front--;
  q->rear--;  
}
else
{
  a=q->d[q->front];
  q->front++;
}
return a;
}

int main()
{
int i=1,l,t,n,time,k=1,p=1,t1=0,t2=0,t3=0,p1=0,p2=0,p3=0,x=1000,s=0,m=1,e;
struct queue q1;
q=&q1;
q->rear=-1;
q->front=-1;
for(i=0;i<MAX;i++)
{
  cin>>t;
  enqueue(t);
}
/*cout<<"Enter for how many printers(1/2/3) do you want to simulate this program";
cin>>k;
if(k<1 && k>3)
  cout<<"Invalid input";
else*/
printf("/n%d %d\n",q->front,q->rear);k=2;
while(k<=2)
{ 
  switch(k++)
  {
    case 1:cout<<"For 1 printer only\n";
           for(i=1;i<=MAX;i++)
           { 
             
             time=0;
             t=dequeue();
       //      printf("/n%d %d\n",q->front,q->rear);
//cout<<time<<"\t"<<t<<"\t";
             n=t/10;
//cout<<n<<endl;
   //for(int h=4;h>=i-1;h--)
     //         {printf("%d ",q->d[h]);}
             if(i+n-1>MAX-1)
               n=MAX-1;
             else
               n=n+i-1;
             merge_sort((q->d),i,n);
                //for(int h=4;h>=i-1;h--)
              //{printf("%d ",q->d[h]);}
             printf("Printing job %d\n",i);
             while(t>0)
             {
               time++;
               t-=10;
             }
             t1+=time;
             printf("Time required to print job is %d\n",time);
             //for(int h=4;h>=i-1;h--)
             // {printf("%d ",q->d[h]);}
               //printf("/n%d %d",q->front,q->rear);  
             
           }
           printf("Total time required to complete all jobs %d\n",t1);break;
    case 2:cout<<"For 2 printers\n";
           //int 
           q->front=0;
           q->rear=MAX-1;
           printf("%d %d \n",q->front,q->rear);
           p1=0,p2=0;s=0;
           for(i=1;i<=MAX;)
           {  e=1;
             p=1;
             l=0;
            
             while(e<=2 && i<=MAX)
             { 
               l=0;
             
               
               time=0;
              switch(m)
              {
               case 1:if(p1==0)
                       {    
                           time=0;            
                           if(l==0)
                           {t=dequeue();
                           l=1;}
                          n=t/10;
                         // printf("j");
                          p=1;
                          p1=n;
                          
                          if(p1!=0)
                            p1--;
                          if(p1==0 || p2==0 )
                            e++; 
                          if(p1>=p2)
                            x=p2;
                          else
                            x=p1;

                           if(l==1)
                          { //printf("k");
                            if(i+x-1>MAX-1)
                              n=MAX-1;
                            else
                              n=x+i;
                            if(x==0)
                              s=1;
                            else
                              s=x;
                            merge_sort((q->d),i,n);
                            printf("Printing job %d on printer %d\n",i,p);
                            while(t>0)
                            { 
                             time++;
                             t-=10;
                            }
                            //t2+=time;
                            printf("Time required to print job is %d\n",time);
                            i++;
                          }
                        t2++;
                       }
              case 2: if(p2==0 )
                      {
                         l=0;
                       if(s>=1 && i<=MAX) 
                        { time=0;
                          if(p2==0 )
                          { 
                            if(l==0)
                              {t=dequeue();l=1;}
                            n=t/10;
                            p=2;
                            p2=n;
                            //x++;
                          
                            if(p2!=0)
                              p2--;
                            if(p1!=0)
                              p1--;
                            if(p1!=0 || p2!=0)
                               e++;
                           if(p1>=p2)
                             x=p2;
                           else
                             x=p1;
                           if(l==1)
                           {
                             if(i+x-1>MAX-1)
                               n=MAX-1;
                             else
                               n=x+i;
                             if(x==0)
                               s=1;
                             else
                               s=x;
                             merge_sort((q->d),i,n);
                             printf("Printing job %d on printer %d\n",i,p);
                             while(t>0)
                             { 
                               time++;
                               t-=10;
                             }
                             //t2+=time;
                             printf("Time required to print job is %d\n",time);
                             i++;
                            }//iif 
                          }//
                       t2++;}//if
                      }
              case 3:if(p1!=0 && p1!=0)
                     {
                      
                       if(p1!=0)
                         p1--;              
                       if(p2!=0)
                         p2--;
                        if(p1>=p2)
                           x=p2;
                        else
                           x=p1;
                        if(x==0)
                          s=1;
                        else
                          s=x;
                    t2++; }
                  }//switch
              }//while
            if(p1!=0)
                 t3=t3+p1;
               else if(p2!=0)
                  t3=t3+p2;}printf("Total time required to complete all jobs %d\n",t2);break;
    case 3:cout<<"For 3 printers\n";
           p1=0;p2=0;p3=0;x=1000;
           q->front=0;
           q->rear=MAX-1;
           printf("%d %d\n",q->front,q->rear);
           s=0;
           for(i=1;i<=MAX;)
           { int e=1;
             p=1;
             l=0;
             printf("%d  \n",i);
             //printf("g");
             while(e<=3 && i<=MAX)
             { 
               l=0;
              //printf("H");
               time=0;
             /* if(p1==0 || p2==0 || p3==0)
               {t=dequeue();
                l=1;}
               else
                i--;
               n=t/10;*/
            
               switch(m)
               {
                
                case 1: if(p1==0 )
                        {    time=0;            
                           if(l==0)
                           {t=dequeue();
                           l=1;}
                          n=t/10;
                         // printf("j");
                          p=1;
                          p1=n;
                          t3++;
                          if(p1!=0)
                            p1--;
                          if(p1==0 || p2==0 || p3==0)
                            e++; 
                          if(p1<=p2 && p1<=p3)
                            x=p1;
                          else if(p2<=p3 && p2<=p1)
                            x=p2;
                          else 
                            x=p3; 
                          if(l==1)
                          { //printf("k");
                            if(i+x-1>MAX-1)
                              n=MAX-1;
                            else
                              n=x+i;
                            if(x==0)
                              s=1;
                            else
                              s=x;
                            merge_sort((q->d),i,n);
                            printf("Printing job %d on printer %d\n",i,p);
                            while(t>0)
                            { 
                             time++;
                             t-=10;
                            }
                            //t3+=time;
                            printf("Time required to print job is %d\n",time);
                            i++;
                          }
                         //t3++; 
                        }
               case 2: l=0;
                       if(s>=1 && i<=MAX) 
                        { time=0;
                          if(p2==0 )
                          { 
                            if(l==0)
                              {t=dequeue();l=1;}
                            n=t/10;
                            p=2;
                            p2=n;
                            //x++;
                            t3++;
                            if(p2!=0)
                              p2--;
                            if(p1!=0)
                              p1--;
                            if(p1==0 || p2==0 || p3==0)
                              e++; 
                            if(p1<=p2 && p1<=p3)
                               x=p1;
                            else if(p2<=p3 && p2<=p1)
                              x=p2;
                            else 
                              x=p3; 
                            if(l==1)
                            {
                              if(i+x-1>MAX-1)
                                n=MAX-1;
                              else
                                n=x+i;
                              if(x==0)
                                s=1;
                              else
                              s=x;
                              merge_sort((q->d),i,n);
                              printf("Printing job %d on printer %d\n",i,p);
                              while(t>0)
                              {  
                                time++;
                                t-=10;
                              }
                              
                              printf("Time required to print job is %d\n",time);
                              i++;
                              }
                
                          //t3++;
                             }  
                         // s++;
                        }
               case 3: l=0;
                       if(s>=1 && i<=MAX)
                       { time=0;
                         if(p3==0 )
                         {  
                            if(l==0)
                              {t=dequeue();l=1;}
                            n=t/10;
                            p=3;
                            p3=n;
                             t3++;
                            if(p1!=0)
                              p1--;              
                            if(p2!=0)
                              p2--;
                            if(p3!=0)
                              p3--;
                            if(p1==0 || p2==0 || p3==0)
                              e++; 
                            if(p1<=p2 && p1<=p3)
                              x=p1;
                            else if(p2<=p3 && p2<=p1)
                              x=p2;
                            else 
                              x=p3; 
                            if(l==1)
                            {
                              if(i+x-1>MAX-1)
                                n=MAX-1;
                              else
                                n=x+i;
                              if(x==0)
                                s=1;
                              else
                                s=x;
                              merge_sort((q->d),i,n);
                              printf("Printing job %d on printer %d\n",i,p);
                              while(t>0)
                              {  
                                time++;
                                t-=10;
                              }
                              //t3+=time;
                              printf("Time required to print job is %d\n",time);
                              i++;
                            }
                         // t3++;
                         }
                       }//if
                case 4:if(p1!=0 && p2!=0 && p3!=0)
                       {   t3++;
                          if(p1!=0)
                              p1--;              
                            if(p2!=0)
                              p2--;
                            if(p3!=0)
                              p3--;
                            if(p1==0 || p2==0 || p3==0)
                              e++; 
                            if(p1<=p2 && p1<=p3)
                               x=p1;
                            else if(p2<=p3 && p2<=p1)
                              x=p2;
                            else 
                              x=p3; 
                            if(x==0)
                                s=1;
                              else
                                s=x; 
                            
                       }
               if(p1!=0)
                 t3=t3+p1;
               else if(p2!=0)
                  t3=t3+p2;
               else if(p3!=0)
                  t3=t3+p3; 
                }//iswitch
              }//iwhile
          }//ifor
  }//switch
}//while
printf("Comparison between simulation using 1 / 2 / 3 printers\n");
printf("Total time required to complete all jobs %d\n",t1);
printf("Total time required to complete all jobs %d\n",t2);
printf("Total time required to complete all jobs %d\n",t3);
return 0;
}
void merge_sort(int a[],int up,int down)
{
int mid=(up+down)/2;
if(up<down)
 {
  merge_sort(a,up,mid);
  merge_sort(a,mid+1,down);
  merge(a,up,down,mid);
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







/*Sir,we are doing a project which implements MPI(Message Passing Interface) on android.The project outline is as follow:
Suppose there's a progra/process which has large number of computations so obviously it will require large amount of time if we run this program on one mobile.So we'll use divide and conquer method.First we'll connect 3-4 mobile devices to one mobile.We will devide the program into several parts and send one part to each mobile which will run it.So simultaneously all mobile will run their respective sub program and send the result to main mobile which will provide the final result.
So any ideas like what all concepts will be required?and any material about MPI?*/
   //cout<<time<<"\t"<<t<<"\t"<<n<<endl;
               /*if(n==2)
                 l=1;
               else if(n>=3)
                 l=2;*/
               //int x;
               /*if(p1!=0)
                  p1--;
                if(p2!=0)
                  p2--;
               if(p3!=0)
                  p3--;
               if(p1==0 || p2==0 || p3==0)
                  e++;
               if(p1<=p2 && p1<=p3)
                  x=p1;
               else if(p2<=p3 && p2<=p1)
                  x=p2;
               else 
                  x=p3; 
              if(l==1)
              {
               if(i+x-1>MAX-1)
                 n=MAX-1;
               else
                 n=x+i;
               s=i-x;
               merge_sort((q->d),i,n);
               printf("Printing job %d on printer %d\n",i,p);
               while(t>0)
               { 
                 time++;
                 t-=10;
               }
               t3+=time;
               printf("Time required to print job is %d\n",time);
               }
                i++;
             }
           }printf("Total time required to complete all jobs %d\n",t1);break;*/

/*if(p1==0 || p2==0)
               {t=dequeue(); 
               l=1;}
              else
                i--;
               
               n=t/10;
                if(p1==0)
                {p=1;
                 p1=n;}
              else if(p2==0)
                {p=2;p2=n;}
              // cout<<time<<"\t"<<t<<"\t"<<n<<endl;
               //int x;
               if(p1!=0)
                  p1--;
               else if(p2!=0)
                  p2--;
               if(p1==0 || p2==0)
                  e++;
               if(p1>=p2)
                 x=p2;
               else
                 x=p1;
               /*if(n==1)
                 l=1;
               else if(n>=2)
                 l=2;
             if(l==1)
             {
               if(i+x-1>MAX-1)
                 n=MAX-1;
               else
                 n=x+i;
               merge_sort((q->d),i,n);
               printf("Printing job %d on printer %d\n",i,p);
               while(t>0)
               { 
                 time++;
                 t-=10;
               }
                t2+=time;
               printf("Time required to print job is %d\n",time);
               } 
                i++;
               
             }*/





