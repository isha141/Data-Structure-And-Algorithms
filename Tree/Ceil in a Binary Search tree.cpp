// T.C=O(N)
// S.C=O(N)




#include<bits/stdc++.h>
using namespace std;
int findCeil(BinaryTreeNode<int> *root, int x){
   if(root==NULL)
			return 0; 
		int ans=INT_MAX;
		while(root!=NULL)
		{
			if(root->data>=x){
				ans=min(ans,root->data);  
				root=root->left;
			}
			else
		  root=root->data<x? root->right:root->left;
		}
        return ans==INT_MAX?-1: ans;
}
