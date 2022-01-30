#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<cstring>
#include<string>

using namespace std;
#define MAX 50

struct tree
{
  string str;
  int n;
  struct tree** ptr;
};

typedef struct tree tree;

tree* create()
{
  tree* root=new tree();
  cout<<"enter drive name\n";
  cin>>root->str;
  
  cout<<"enter number of folders\n";
  cin>>root->n;
  //cout<<root->n;
  root->ptr=new tree*[root->n];
  
  for(int i=0;i<root->n;i++)
  {
     
    root->ptr[i]=new tree;
    cout<<"enter name of folder\n";
    cin>>root->ptr[i]->str;
    cout<<"enter no of files in "<<root->ptr[i]->str<<endl;
    cin>>root->ptr[i]->n;
    root->ptr[i]->ptr=new tree*[root->ptr[i]->n];
    
    
    for(int j=0;j<root->ptr[i]->n;j++)
    {
      root->ptr[i]->ptr[j]=new tree;
      cout<<"enter name of file\n";
      cin>>root->ptr[i]->ptr[j]->str;
      root->ptr[i]->ptr[j]->ptr=NULL;
      root->ptr[i]->ptr[j]->n=0;
    }
   
 
  }
  return root; 
}


tree* traverse_folder(tree* root,string folder)
{
  for(int i=0;i<root->n;i++)
  {
     if(root->ptr[i]->str == folder )
       {
        return root->ptr[i];
       }
  }
  return NULL;
}


tree* traverse_file(tree* temp,string file)
{
  for(int i=0;i<temp->n;i++)
  {
     if(temp->ptr[i]->str==file)
        return temp->ptr[i];
  }
  return NULL;
}


void add_folder(tree *root,string folder)
{
  
  (root->n)++;
  root->ptr=(tree**)realloc(root->ptr,root->n*sizeof(tree*));
  root->ptr[(root->n)-1]=new tree;
  
  root->ptr[root->n-1]->str=folder;
  cout<<"enter no of  files in "<<root->ptr[root->n-1]->str<<endl;
  cin>>root->ptr[root->n-1]->n;
  root->ptr[root->n-1]->ptr=new tree*[root->ptr[root->n-1]->n];

  for(int j=0;j<root->ptr[root->n-1]->n;j++)
  {
    root->ptr[root->n-1]->ptr[j]=new tree;
    cout<<"enter name of new file\n";
    cin>>root->ptr[root->n-1]->ptr[j]->str;
    root->ptr[root->n-1]->ptr[j]->ptr=NULL;
    root->ptr[root->n-1]->ptr[j]->n=0;
   }     
}


void add_file(tree *temp,string file)
{
  temp->n++;
  temp->ptr=(tree**)realloc(temp->ptr,temp->n*sizeof(tree*));
  temp->ptr[temp->n-1]=new tree;
  
  temp->ptr[temp->n-1]->str=file;
  temp->ptr[temp->n-1]->n=0;
  temp->ptr[temp->n-1]->ptr=NULL;

}


void delete_folder(tree* root,string folder)
{
  tree *t;
  int i;
  if(root->n>0)
  {
    for(i=0;i<root->n;i++)
    {
      if(root->ptr[i]->str==folder)
      {
        t=root->ptr[i];
        break;
      }
    }

    for(int j=i+1;j<root->n;j++)
    {
      root->ptr[j-1]=root->ptr[j];
    }
  
    for(int k=0;k<t->n;k++)
    {
      delete t->ptr[k];
    }
  
    delete t->ptr;
  
    root->n--;
    root->ptr=(tree**)realloc(root->ptr,root->n*sizeof(tree*));
  }
  else
    cout<<"\nno folders left to be deleted";
}


void delete_file(tree* temp,string file)
{
  int i;
  tree* t;

  if(temp->n>0)
  {
    for(i=0;i<temp->n;i++)
    {
      if(temp->ptr[i]->str==file)
      {
        t=temp->ptr[i];
        break;
      }
    }
  
    for(int j=i+1;j<temp->n;j++)
    {
      temp->ptr[j-1]=temp->ptr[j];
    }
  
    delete t->ptr;
  
    temp->n--;
    temp->ptr=(tree**)realloc(temp->ptr,temp->n*sizeof(tree*));
  }
  else
    cout<<"\nno files left to be deleted";
}


void print_folders(tree* root)
{
  for(int i=0;i<root->n;i++)
  {
    cout<<root->ptr[i]->str<<endl;
  }
}


void print_files(tree *temp)
{
  for(int i=0;i<temp->n;i++)
  {
    cout<<temp->ptr[i]->str<<endl;
  }
}


int main()
{ 
  string file,folder;
  tree* root=create();
  tree *folderp,*filep;
  int ch;
  while(ch!=8)
  {
    cout<<"\n\nenter the number to perform the corresponding operations\n1.search  2.add folder  3.add file  4.delete folder  5.delete file  6.print folders  7.print files\n";
    cin>>ch;
    
    switch(ch)
    {
      case 1:do
             {
               cout<<"\nenter folder name to be searched\n";
               cin>>folder;
               folderp=traverse_folder(root,folder);
             }while(folderp==NULL);

               cout<<folderp->str<<" found"<<endl;
  
             do
             {
               cout<<"enter file name to be searched\n";
               cin>>file;
               filep=traverse_file(folderp,file);
             }while(filep==NULL);
  
             cout<<filep->str<<" found\n";
             break;

      case 2:cout<<"\nenter the name of new folder\n";
             cin>>folder;
             add_folder(root,folder);
             cout<<"\nnew folder has been added successfully!\n";
             break;

      case 3:do
             {
               cout<<"\nenter folder name where new  file is to be added\n";
               cin>>folder;
               folderp=traverse_folder(root,folder);
             }while(folderp==NULL);
             cout<<"enter the name of new file\n";
             cin>>file;
             add_file(folderp,file);
             cout<<"new file has been added successfully!\n";
             break;
      
      case 4:if(root->n>0)
             {
               cout<<"\nenter the name of the folder to be deleted\n";
               cin>>folder;
               delete_folder(root,folder);
               cout<<"folder has been deleted successfully!\n";
             }
             else
               cout<<"\nno folders left to be deleted";
             break;

      case 5:do
             {
               cout<<"\nenter folder name from which file is to be deleted\n";
               cin>>folder;
               folderp=traverse_folder(root,folder);
             }while(folderp==NULL);
      
             if(folderp->n>0) 
             {  
               cout<<"enter the name of the file to be deleletd\n";
               cin>>file;
               delete_file(folderp,file);
               cout<<"file has been deleted successfully!\n";
             }
             else
               cout<<"\nno files left to be deleted";
             break;
      case 6:cout<<"\nlists of folders in "<<root->str<<" is\n";
             print_folders(root);
             break;
      case 7:do
             {
               cout<<"\nenter folder name from which all files are to be displayed\n";
               cin>>folder;
               folderp=traverse_folder(root,folder);
             }while(folderp==NULL);
             cout<<"\nlists of files in "<<folderp->str<<" is\n";
             print_files(folderp);
             break;
      default:ch=8;
    }
  }
  
  return 0;
}
