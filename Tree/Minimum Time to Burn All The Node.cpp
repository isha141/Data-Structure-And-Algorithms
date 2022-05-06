// T.C=O(N)+O(N)
// S.C=O(N)+O(N)


#include<bits/stdc++.h>
using namespace std; 
BinaryTreeNode<int>*res;
void parent(BinaryTreeNode<int>* root,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&mp,int start)
{
	if(root==NULL)
		return ;
	if(root->data==start)
		res=root;
	if(root->left==NULL && root->right==NULL)
		return ;
	parent(root->left,mp,start);
	if(root->left)
		mp[root->left]=root; 
    parent(root->right,mp,start);
	if(root->right)
	    mp[root->right]=root;
} 

int burn(BinaryTreeNode<int>* root,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&mp)
{
	int count=0;
	queue<BinaryTreeNode<int>*>q;
	q.push(root); 
	map<BinaryTreeNode<int>*,bool>visited; 
	visited[root]=true;
	while(!q.empty())
	{
		int flag=0;
		int n=q.size();
		for(int i=0;i<n;i++){ 
		BinaryTreeNode<int>* temp=q.front();
		  q.pop(); 
		if(temp->left && !visited[temp->left])
		{ 
			flag=1;
			q.push(temp->left);
			visited[temp->left]=true;
		}
		if(temp->right && !visited[temp->right])
		{ 
			flag=1;
			q.push(temp->right);
			visited[temp->right]=true;
		}
		if(mp[temp] && !visited[mp[temp]])
		{ 
			flag=1;
			q.push(mp[temp]);
			visited[mp[temp]]=true;
		}
		} 
		if(flag)
			count++;
	}
	return count;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
   int count=0; 
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>mp;
	parent(root,mp,start); 
	return burn(res,mp);
	
}
