#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#define MAX 50


struct tree
{
  int data;
  struct tree* l;
  struct tree* r;
};

typedef struct tree tree;
typedef struct tree avl;

struct queue
{
  tree* d[MAX];
  int front;
  int rear;
}*q;


struct stack
{
  tree* a[MAX];
  int top;
}*s;


void push(tree*);
tree* pop();
void enqueue(tree*);
tree* dequeue();
int isFull();
int isEmpty();
int sizeq();
tree* create(int);
tree* createbst(int);
tree* deletebst(tree*,int);
avl* createavl(int);
avl* insert(avl*,int);
avl* rotate_left(avl*);
avl* rotate_right(avl*);
avl* rotate_ll(avl*);
avl* rotate_rr(avl*);
avl* rotate_lr(avl*);
avl* rotate_rl(avl*); 
void inorder(tree*);
void inorderR(tree*);
void postorder(tree*);
void postorderR(tree*);
void preorderR(tree*);
void preorder(tree*);
void mirror(tree*);
void mirrorR(tree*);
void levelorder(tree*);
void levelorderR(tree*,int);
void printlevelorder(tree*);
int height(tree*);
int heightr(tree*);




int main()
{
  struct queue h;
  q=&h;
  q->rear=q->front=-1;
  struct stack s1;
  s=&s1;
  s->top=-1;
  int n,d;
  cout<<"normal tree\n";
  cout<<"enter no of elements";
  cin>>n;
  tree* root=create(n);
  

  cout<<"\ninorder is\n";
  inorderR(root);cout<<endl;
  inorder(root);
  cout<<"\npostorder is\n";
  postorderR(root);cout<<endl;
  postorder(root);
  cout<<"\npreorder is\n";
  preorderR(root);cout<<endl;
  preorder(root);
  cout<<"\nlevelorder is\n";
  levelorder(root);cout<<endl;
  printlevelorder(root);
  cout<<"\nheight of tree is\n";
  cout<<heightr(root)<<endl;;
  cout<<height(root);
  cout<<"\nmirror image of tree in level order is\n";
  mirrorR(root);
  levelorder(root);
  mirror(root);
  cout<<"\noriginal tree in level order is\n";
  printlevelorder(root);cout<<endl;
  /*cout<<"\nenter the element to be deleted\n";
  cin>>d;
  root=deletebst(root,d);
  cout<<"\nelement has been deleted";
  levelorder(root);cout<<endl;
  root=deletebst(root,35);
  levelorder(root);cout<<endl;
  root=deletebst(root,31);
  levelorder(root);cout<<endl;
  root=deletebst(root,21);
  levelorder(root);cout<<endl;*/


  cout<<"\nbst tree\n";
   cout<<"enter no of elements";
  cin>>n;
  root=createbst(n);
   cout<<"\ninorder is\n";
  inorderR(root);cout<<endl;
  inorder(root);
  cout<<"\npostorder is\n";
  postorderR(root);cout<<endl;
  postorder(root);
  cout<<"\npreorder is\n";
  preorderR(root);cout<<endl;
  preorder(root);
  cout<<"\nlevelorder is\n";
  levelorder(root);cout<<endl;
  printlevelorder(root);
  cout<<"\nheight of tree is\n";
  cout<<heightr(root)<<endl;;
  cout<<height(root);
  cout<<"\nmirror image of tree in level order is\n";
  mirrorR(root);
  levelorder(root);
  mirror(root);
  cout<<"\noriginal tree in level order is\n";
  printlevelorder(root);cout<<endl;
  cout<<"\nenter the element to be deleted\n";
  cin>>d;
  root=deletebst(root,d);
  cout<<"\nelement has been deleted";
  levelorder(root);cout<<endl;


  cout<<"\navl tree\n";
   cout<<"enter no of elements";
  cin>>n;
  root=createavl(n);
  cout<<"\ninorder is\n";
  inorderR(root);cout<<endl;
  inorder(root);
  cout<<"\npostorder is\n";
  postorderR(root);cout<<endl;
  postorder(root);
  cout<<"\npreorder is\n";
  preorderR(root);cout<<endl;
  preorder(root);
  cout<<"\nlevelorder is\n";
  levelorder(root);cout<<endl;
  printlevelorder(root);
  cout<<"\nheight of tree is\n";
  cout<<heightr(root)<<endl;;
  cout<<height(root);
  cout<<"\nmirror image of tree in level order is\n";
  mirrorR(root);
  levelorder(root);
  mirror(root);
  cout<<"\noriginal tree in level order is\n";
  printlevelorder(root);cout<<endl;
  
  cout<<"\nenter the element to be deleted\n";
  cin>>d;
  root=deletebst(root,d);
  cout<<"\nelement has been deleted";
  levelorder(root);cout<<endl;
  return 0;
}


tree* create(int n)
{
  tree* root=NULL;
  int f;
  tree* temp=new tree();
  temp->l=NULL;
  temp->r=NULL;
  cout<<"enter the element"; 
  cin>>temp->data;
  for(int i=0;i<n;i++)
  {
    tree* q;
    if(root==NULL)
      root=temp;
    else
    {
      tree* t=root;
      while(t!=NULL)
      {
        cout<<"enter 1 for left child and 2 for right child";
        cin>>f;
        if(f==1)
        {
          q=t;
          t=t->l;
        }
        else if(f==2)
        {
          q=t;
          t=t->r;
        }
        else
          cout<<"enter valid no";
      }
      t=new tree();
      t->l=NULL;
      t->r=NULL;
      cout<<"enter the element"; 
      cin>>t->data;
      if(f==1)
        q->l=t;
      else if(f==2)
        q->r=t;
      else
        cout<<"enter valid no";
    }   
  }
  return root;
}


tree* createbst(int n)
{
  tree *root=NULL;
  
  for(int i=0;i<n;i++)
  {
    tree *temp,*p; 
    
    if(root==NULL)
    {
      temp=new tree();
      cout<<"enter the element";
      cin>>temp->data;
      temp->l=temp->r=NULL; 
      root=temp;
    }
    else
    {
      temp=root;
      int d;
      cout<<"enter the element";
      cin>>d;

      while(temp!=NULL)
      {
        if(temp->data>d)
        {
          p=temp;
          temp=temp->l; 
        }
        else if(temp->data<d)
        {
          p=temp;
          temp=temp->r; 
        }
      }
      temp=new tree();
      temp->data=d;
      temp->r=temp->l=NULL;      

      if(p->data>d)
         p->l=temp;
      else
         p->r=temp;
    }
  }
  return root;
}


tree* deletebst(tree *root,int key)
{
  tree *r=root;
  tree *p=NULL; 
  tree *nroot=root; 

  if(r->data!=key)
  {   
    q->rear=q->front=-1;
    if(r!=NULL)
      enqueue(r);
    
    while(!isEmpty())
    {
      r=dequeue(); 
      if(r->l!=NULL)
      {
         if(r->l->data == key)
          {
            p=r->l;
            break;
          }
      }
      if(r->r!=NULL)
      {
         if(r->r->data == key)
         {
           p=r->r;
           break;
         }
      }
      if(r!=NULL);
      { 
        if(r->l!=NULL)  
          enqueue(r->l);
        if(r->r!=NULL)
          enqueue(r->r);
      }
    }
  }
  

  if(p==NULL) //node to be deleted is root
  {
     if(r->l == NULL && r->r == NULL && r->data == key) // leaf root node
     {
       //cout<<"hi";
       delete r;
       nroot=NULL;
       return nroot;
     }
     else if(r->l == NULL && r->data == key)  // root node has 1 right child
     {
       nroot=r->r;
       delete r;
       return nroot;
     }
     else if(r->r == NULL&& r->data == key ) // root node has 1 left child
     {
       nroot=r->l;
       delete r;
       return nroot;
     }
     else if( r->data == key)                // root node has two childs
     {
       tree *t1,*t2;                // t1 is inorder successor & t2 is parent of it
       t2=p;
       t1=r->r;

       while(t1->l!=NULL)
       { 
         t2=t1;
         t1=t1->l;
       }

       if(t1->r==NULL)
       {
          r->data=t1->data;
          delete t1;
          t2->l=NULL;
       }
       else
       {
          r->data=t1->data;
          t2->l=t1->r;
          delete t1;
       }
       return nroot;
     }
     //cout<<"bye";
     return nroot;
  }
  else
  {
    // p is to be deleted and r is parent
    if( p->l == NULL && p->r == NULL) // is leaf node
    {
      if(r->l == p)
      {
        r->l=NULL;
        delete p;
      }
      else if(r->r == p)
      {
        r->r=NULL;
        delete p;
      }  
    }  
    else if( p->l == NULL) // has 1 right node
    {
      if(r->l==p)
      {
        r->l=p->r;
        delete p;
      }
      else if(r->r==p)
      {
        r->r=p->r;
        delete p;
      }
    }
    else if(p->r == NULL) // has 1 left node
    {
      if(r->l==p)
      {
        r->l=p->l;
        delete p;
      }
      else if(r->r==p)
      {
        r->r=p->l;
        delete p;
      }
    }
    else  // has 2 nodes
    {
      tree *t1,*t2;
      t1=p->r;
      t2=p;
   cout<<"p "<<p->data<<" t1 "<<t1->data<<" t2 "<<t2->data<<endl;
      while(t1->l!=NULL)
       { 
         t2=t1;
         t1=t1->l;
       }
cout<<"p "<<p->data<<" t1 "<<t1->data<<" t2 "<<t2->data<<endl;
       if(t1->r==NULL)
       {
          p->data=t1->data;
          delete t1;
          if(t2==p)
            t2->r=NULL;
          else
            t2->l=NULL;
       }
       else
       {
          p->data=t1->data;
          t2->l=t1->r;
          delete t1;
       } 
    }

  return nroot;    
  }
  
}


avl* createavl(int n)
{
  avl *root=NULL;
  int d;
  for(int i=0;i<n;i++)
  {
    cout<<"enter element";
    cin>>d;
    root=insert(root,d);
  }
  return root;
}


avl* insert(avl* t,int d)
{
  if(t==NULL)
  {
    t=new avl;
    t->data=d;
    t->l=t->r=NULL;
    return t;
  }
  else
  {
    if(t->data>d)
    {
      t->l=insert(t->l,d);
      int bf=height(t->l)-height(t->r);
      if(bf==2)
      {
        if(t->l->data<d)
          t=rotate_lr(t);
        else
          t=rotate_ll(t);
      }
    }
    else
    {
      t->r=insert(t->r,d);
      int bf=height(t->l)-height(t->r);
      if(bf==-2)
      {
        if(t->r->data<d)
          t=rotate_rr(t);
        else
          t=rotate_rl(t);
      }
    } 
    return t;
  }
}

 
avl* rotate_right(avl* t)
{
  avl* y=t->l;
  t->l=y->r;
  y->r=t;
  return y;
}


avl* rotate_ll(avl* t)
{
  t=rotate_right(t);
  return t;
}


avl* rotate_left(avl* t)
{
  avl* y=t->r;
  t->r=y->l;
  y->l=t;
  return y;
}


avl* rotate_rr(avl* t)
{
  t=rotate_left(t);
  return t;
}


avl* rotate_lr(avl* t)
{
  t->l=rotate_left(t->l);
  t=rotate_right(t);
  return t;
}


avl* rotate_rl(avl* t)
{
  t->r=rotate_right(t->r);
  t=rotate_left(t);
  return t;
}


void inorder(tree* r)
{
  while(r!=NULL)
  {
    push(r);
    r=r->l;
  }
  while(s->top!=-1)
  {
    r=pop();
    cout<<r->data<<" ";
    if(r->r!=NULL)
    {
      r=r->r;
      while(r!=NULL)
      {
        push(r);
        r=r->l;
      }
    }
  }
}


void inorderR(tree* r)
{
  if(r!=NULL)
  {
    inorderR(r->l);
    cout<<r->data<<" ";
    inorderR(r->r);
  }
}


void postorder(tree* r)
{
  while(r!=NULL)
  {
    if(r->r!=NULL)
      push(r->r);
    push(r);
    r=r->l;
  }
  while(s->top!=-1)
  {
    r=pop();
    if((s->a[s->top])==r->r && r->r!=NULL)
    {
      tree* t=pop();
      push(r);
      r=t;
      while(r!=NULL)
      {
        if(r->r!=NULL)
          push(r->r);
        push(r);
        r=r->l;
      }
    }
    else
      cout<<r->data<<" ";
    
  }

}


void postorderR(tree* r)
{
    if(r!=NULL)
  {
    postorderR(r->l);
    postorderR(r->r);
    cout<<r->data<<" ";
  }
}


void preorder(tree* r)
{
  while(r!=NULL)
  {
    cout<<r->data<<" ";
    if(r->r!=NULL)
      push(r->r);
    r=r->l;
  }
  while(s->top!=-1)
  {
    r=pop();
    while(r!=NULL)
    {
      cout<<r->data<<" ";
      if(r->r!=NULL)
        push(r->r);
      r=r->l;
    }
  }
}


void preorderR(tree* r)
{
    if(r!=NULL)
  {
    cout<<r->data<<" ";
    preorderR(r->l);
    preorderR(r->r);
  }
}


void levelorder(tree* r)
{
  q->rear=q->front=-1;
  if(r!=NULL)
    enqueue(r);
  while(!isEmpty())
  {
    r=dequeue();
    if(r!=NULL);
    {cout<<r->data<<" ";
    
    if(r->l!=NULL)
      enqueue(r->l);
    if(r->r!=NULL)
      enqueue(r->r);}
  }
}


void levelorderR(tree* r,int level)
{
  if(r==NULL)
    return;
  if(level==1)
    cout<<r->data<<" ";
  else if(level>1)
  {
    levelorderR(r->l,level-1);
    levelorderR(r->r,level-1);
  }
}


void printlevelorder(tree*r)
{
  int h=height(r);
  for(int i=1;i<=h;i++)
  {
    levelorderR(r,i);
  }

}

void mirror(tree* r)
{
  q->rear=q->front=-1;
  if(r!=NULL)
    enqueue(r);
  while(!isEmpty())
  {
    r=dequeue();
    tree* temp=r->l;
    r->l=r->r;
    r->r=temp;
    if(r->l!=NULL)
      enqueue(r->l);
    if(r->r!=NULL)
      enqueue(r->r);
  }
}


void mirrorR(tree* r)
{
  if(r==NULL)
    return;
  else
  {

           mirrorR(r->l);
    mirrorR(r->r);
    tree* t=r->l;
    r->l=r->r;
    r->r=t;

  } 
}


int height(tree* r)
{
  q->rear=q->front=-1;
  int h=0;
  if(r!=NULL)
    enqueue(r);
  while(!isEmpty())
  {
    h++;
    int f=sizeq();
    while(f--)
    {
      r=dequeue();
      if(r->l!=NULL)
        enqueue(r->l);
      if(r->r!=NULL)
        enqueue(r->r);
    }    
  }
  return h;
}


int heightr(tree* r)
{
  if(r==NULL)
    return 0;
  else
  {
    int lh=heightr(r->l);
    int rh=height(r->r);
    if(lh>rh)
      return lh+1;
    else
      return rh+1;
  }
 
}

void enqueue(tree* a)
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


tree* dequeue()
{
tree* a=NULL;
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


int isFull()
{
    if( (q->front == q->rear + 1) || (q->front == 0 && q->rear == MAX-1)) return 1;
    return 0;
}


int isEmpty()
{
    if(q->front == -1 || q->front>q->rear) return 1;
    return 0;
}


int sizeq()
{
  return (q->rear - q->front + 1);
}


void push(tree* c)
{
  if(s->top==MAX-1)
    cout<<"Stack overflow";
  else
  {
    s->top++;
    s->a[s->top]=c;
  }  
}


tree* pop()
{
  tree* c;
  if(s->top==-1)
    printf("Stack underflow");
  else
    {c=s->a[s->top];
     s->top--;}
 return c;
}
