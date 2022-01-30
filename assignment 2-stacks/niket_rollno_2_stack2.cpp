
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int g; 
    scanf("%d",&g);
    for(int a0 = 0; a0 < g; a0++)
    {
        int n; 
        int m; 
        int x; 
        scanf("%d %d %d",&n,&m,&x);
        int *stack1 = (int*)malloc(sizeof(int) * n);
        for(int a_i = 0; a_i < n; a_i++){
           scanf("%d",&stack1[a_i]);
        }
        int *stack2 = (int*)malloc(sizeof(int) * m);
        for(int b_i = 0; b_i < m; b_i++){
           scanf("%d",&stack2[b_i]);
        }
        int top1=0,top2=0;
        int score=0,check1=0,check2=0,check=0;
        int cnt1=0,ct1=0,ct2=0,cnt2=0;
        for(int i=0;(check1+stack1[i])<=x  ;i++)
        {
            if((check1+stack1[i])<=x)
            {  //printf("%d\t",stack1[i]);
             check1+=stack1[i];   
             cnt1++;
            }  
          
        }
          ct1=cnt1;
        for(int i=0;(check2+stack2[i])<=x  ;i++)
        {
            if((check2+stack2[i])<=x)
            {
                  check2+=stack2[i];  
               // printf("%d\t",stack2[i]);
                cnt2++;
            }  
            
        }
        ct2=cnt2;
      // printf("c %d %d ",ct1,ct2);
        while(check<x && top1!=n-1 && top2!=m-1)
        {
            cnt1=0;
            cnt2=0;
            check1=0;
            check2=0;
        for(int i=top1;i<ct1 ;i++)
        {
            if((check1+stack1[i])<=x)
            {
                cnt1++;
                check1+=stack1[i];
            }  
          
        }
      // printf("S %d",check1);
          for(int i=top2;i<ct2;i++)
        {
            if((check2+stack2[i])<=x)
            {
                cnt2++;
                check2+=stack2[i];
            }   
        }
        
        // printf(" %d ",check2);
            
        //check=0;
            if(check1>check2 && abs(cnt2-cnt1)<=2  && check2!=0 && (check+stack2[top2])<=x)
                {
                    check+=stack2[top2];
                    top2++;
                    score++;
               // printf("sum %d %d\n",stack2[top2-1],score );
                    
                }
                else if(check1<check2 && abs(cnt2-cnt1)<=2 && check1!=0 && (check+stack1[top1])<=x  )
                {
                    check+=stack1[top1];
                    top1++; 
                    score++;
                     // printf("sum %d %d\n",stack1[top1-1],score);
                    
                }
                else if(cnt1>cnt2 && (check+stack1[top1])<=x)
            {
                check+=stack1[top1];
                 top1++;
             //  printf("cnt %d ",stack1[top1-1]);
           // printf("%d\n",++score);
            score++;
        }
        else if(cnt1<cnt2 && cnt1!=0 && cnt2!=0 && (check+stack2[top2])<=x)
        {
            check+=stack2[top2];
            top2++;
           // printf("cnt %d ",stack2[top2-1]);
            //printf("%d\n",++score);
           score++;
        }
        else
        {
             if(stack1[top1]>stack2[top2]  && (check+stack2[top2])<=x)
            {
                if((check+stack2[top2])<=x)
                {check+=stack2[top2];
                top2++;
           // printf("comp %d ",stack2[top2-1]);
                }
                else
                    break;
            }
            else if(stack1[top1]<stack2[top2] && (check+stack1[top1])<=x )
            {
                 if((check+stack1[top1])<=x)
                 {check+=stack1[top1];
                top1++;   
                //  printf("comp %d ",stack1[top1-1]);
                 }
                else
                    break;
            }
            else
            {
                
                
                
                if(stack1[top1+1]>stack2[top2+1] )
                {
                     if((check+stack2[top2])<=x)
                     {check+=stack2[top2];
                    top2++;   
                   // printf("%d ",stack2[top2-1]);
                     }
                    else
                        break;
                }
                else 
                {
                     if((check+stack1[top1])<=x)
                     { check+=stack1[top1];
                    top1++;
                     // printf("%d ",stack1[top1-1]);
                     }
                    else
                        break;
                }
                
                //       printf("%d\n",++score);
                score++;
            }
            }
    
            
        }
                
        
        int score2=0;
        top1=0;
        top2=0;
        while(top1!=n-1 && top2!=m-1 )
        {
            if(stack1[top1]>stack2[top2])
            {
                if((check+stack2[top2])<=x)
                {check+=stack2[top2];
                top2++;
               // printf("2 %d\n",stack2[top2-1]);
                }
                else
                    break;
            }
            else if(stack1[top1]<stack2[top2] )
            {
                 if((check+stack1[top1])<=x)
                 {check+=stack1[top1];
                top1++;   
                  // printf("1 %d\n",stack1[top1-1]);
                 }
                else
                    break;
            }
            else
            {
                if(stack1[top1+1]>stack2[top2+1] )
                {
                     if((check+stack2[top2])<=x)
                     {check+=stack2[top2];
                    top2++;   
                     // printf("1 %d\n",stack2[top2-1]);
                     }
                    else
                        break;
                }
                else 
                {
                     if((check+stack1[top1])<=x)
                     { check+=stack1[top1];
                    top1++;
                      //printf("2 %d\n",stack1[top1-1]);
                     }
                    else
                        break;
                }
            }
            score2++;
        }
        if(score>score2)
        printf("%d\n",score);
        else
             printf("%d\n",score2);
            
    }
    return 0;
}
