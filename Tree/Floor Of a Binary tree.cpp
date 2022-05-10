// T.C=O(N)
// S.C=O(N)




int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here. 
	int ans=INT_MIN;
	while(root)
	{ 
// 		if(root->val==X)
// 			return root->val;
		 if(root->val<=X)
		{
			ans=max(ans,root->val);
             root=root->right;
		}
		else 
			root=root->left;
	}
	return ans==INT_MIN?-1:ans;
}
