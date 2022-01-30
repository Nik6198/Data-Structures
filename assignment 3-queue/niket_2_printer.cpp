#include<stdio.h>
//#include<conio.h>
#include<malloc.h>
//#include<alloc.h>
void sort();
struct jobs
{
	int id, pages;
};
struct queue
{
	struct jobs wait[99];
	int front,rear, size;
}q;
void enque(struct jobs j)
{
	if (q.rear == 98)
	{
		printf("quefull\n");
		//getche();
	}
	else
	{
		q.rear++;
		q.wait[q.rear] = j;
	}

}
struct jobs dequeue()
{
	struct jobs j = { 0 };
	if (q.rear >= q.front);
	{
		j = q.wait[q.front];
		q.front++;
	}
	return j;

}
int check(struct jobs *t, int *printer,int id)
{
	if (t->id == 0)
		return 1;
	if (*printer <= 10)
	{
		printf("PRINTER %d : ID %d , pages %d done \n",id, t->id, t->pages);
		*t = dequeue();
		*printer = t->pages;
                if(t->pages!=0)
		printf("printer %d : ID %d , pages %d received\n", id,t->id, t->pages);
		return 0;
	}
	else
	{
		*printer = *printer - 10;
		//printf("print job of ID %d and pages remaining %d\n", t->id, *printer);
		return 0;
	}
}
int printer1(struct jobs *pjobs)
{
        q.front=0;
        q.rear=-1;
	struct jobs t = pjobs[0];
	int time=0;
	int i = 0, printer = t.pages;
	printf("printer 1 : ID %d , pages %d received\n", t.id,t.pages);
	while (i < q.size || t.id != 0)
	{
		time++;
		check(&t,&printer,1);
		i++;
		if (i < q.size)
		{
			enque(pjobs[i]);
                        sort();
		}
	}
	printf("\ntotal time : %d minutes\n", time);
	return time;
}
int printer2(struct jobs*pjobs)
{
	struct jobs t1 = pjobs[0], t2 = { 0 };
	int i=0,flag1=0,flag2=1, print1=t1.pages,print2=0;
	int time=0;
	q.front = 0;
	q.rear = -1;
	printf("printer 1 : ID %d , pages %d received\n", t1.id, t1.pages);
	while (i < q.size || t1.id != 0 || t2.id != 0)
	{       

                if(i<q.size)
                { enque(pjobs[i]);
                sort();}
		time++;
		flag1 = check(&t1, &print1,1);
		flag2 = check(&t2, &print2,2);
		i++;
		if (i < q.size)
		{
			
			if (flag1 == 1)
			{
				t1 = dequeue();
				print1 = t1.pages;
			}				
			else if (flag2 == 1)
			{
				t2 = dequeue();
				print2 = t2.pages;
			}
		}
	}
	printf("\n\ntotal time : %d minutes\n", time);
	return time;
}
int printer3(struct jobs *pjobs)
{
	struct jobs t1 = pjobs[0], t2 = { 0 }, t3 = { 0 };
	int i = 0, flag1 = 0, flag2 = 1, flag3=0, print1 = t1.pages, print2 = 0,print3=0;
	int time = 0;
	q.front = 0;
	q.rear = -1;
	//printf("\ntotal time : %d minutes\n", time);
	printf("printer 1 : ID %d , pages %d received\n", t1.id, t1.pages);
	while (i < q.size || t1.id != 0 || t2.id != 0 || t3.id != 0)
	{
                if(i<q.size)
                {
                enque(pjobs[i]);
                sort();}
		time++;
		flag1 = check(&t1, &print1,1);
		flag2 = check(&t2, &print2,2);
		flag3 = check(&t3, &print3,3);
		i++;
		if (i < q.size)
		{
			
			if (flag1 == 1)
			{
				t1 = dequeue();
				print1 = t1.pages;
			}
			else if (flag2 == 1)
			{
				t2 = dequeue();
				print2 = t2.pages;
			}
			else if (flag3 == 1)
			{
				t3 = dequeue();
				print3 = t3.pages;
			}
		}
	}
	printf("\n\ntotal time : %d minutes\n", time);
	return time;
}

void sort()
{
  for(int i=q.front;i<=q.rear;i++)
  {
    for(int j=q.front+1;j<=q.rear-i;j++)
    {
      if(q.wait[i].pages>q.wait[j].pages)
      {
        int temp=q.wait[i].pages;
        q.wait[i].pages=q.wait[j].pages;
        q.wait[j].pages=temp;
      }
    }
  }
}

int main()
{
	struct jobs *pjobs = NULL;
	int i, time1 = 0, time2 = 0, time3 = 0;
	printf("how many jobs do you have\n");
	scanf("%d", &q.size);
	pjobs = (struct jobs*)malloc(sizeof(struct jobs)*q.size);
	for (i = 0; i < q.size; i++)
	{
		pjobs[i].id = i + 1;
		printf("enter number of pages maximum 50\n");
		scanf("%d", &pjobs[i].pages);
	}
	printf("jobs and their IDs are as follows\n\n");
	for (i = 0; i < q.size; i++)
	{
		printf("ID : %d ", pjobs[i].id);
		printf("number of pages %d\n", pjobs[i].pages);
	}
	printf("\n***************USING 1 PRINTER***************\n");
	time1 = printer1(pjobs);
	printf("\nprss enter for next CASE");
	//getche();
	printf("\n***************USING 2 PRINTERS***************\n");
	time2=printer2(pjobs);
	printf("\nprss enter for next CASE");
	//getche();
	printf("\n***************USING 3 PRINTERS***************\n");
	time3=printer3(pjobs);
	printf("the same set of jobs when done with:\n 1 PRINTER = %d\n 2 PRINTERS = %d\n 3 PRINTERS = %d\n",time1,time2,time3);
	free(pjobs);
	//getche();
	return 0;
}
