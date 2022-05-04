// T.C=O(N)
// S.C=O(N)    /// maximum height of the tree 

#include<bits/stdc++.h>
using namespace std;
class node{ 
   public :
   node *left;
   node *right;
   int data;
   node (int x){
      this->data=x;
      this->left=NULL;
      this->right=NULL;
   }
}; 
void inorder(node *root)
{  
   if(root==NULL)
   return ;
   int l=0;
   int r=0;
   if(root->left)
   l+=root->left->data;
   if(root->right)
   l+=root->right->data;
   if(l>=root->data)
   root->data=l;
   else {
      if(root->left)
      root->left->data=root->data;
      if(root->right)
      root->right->data=root->data;
   }
   inorder(root->left);
   inorder(root->right);
   int tot=0;
   if(root->left)
   tot+=root->left->data;
   if(root->right)
   tot+=root->right->data;
   if(root->left|| root->right)
   root->data=tot;
}
void show(node *root)
{
   if(root==NULL)
   return ;
   else{
      show(root->left);
      cout<<root->data<<" ";
      show(root->right);
   }
}
int main()
{
   
     node *root = new node(50);
    root->left = new node(7);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(1);
    root->right->right = new node(30); 
   // inorder(root);
    cout<<"Before applying children sum property "<<endl;
    show(root); 
    cout<<endl;
    cout<<"After applying children sum property "<<endl;
    inorder(root);
    show(root);
    return 0;  
}
