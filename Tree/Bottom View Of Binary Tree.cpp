// T.C=O(N)
// S.C=O(N)
#include<bits/stdc++.h>
using namespace std;
void solve(BinaryTreeNode<int> * root,vector<int>&ans)
{
	queue<pair<BinaryTreeNode<int> *,int>>q;
	map<int,int>mp;
	int x=0; 
	q.push({root,0});
	while(!q.empty())
	{
		int n=q.size();
		for(int i=0;i<n;i++)
		{
			auto itr=q.front();
			q.pop();
			BinaryTreeNode<int> *temp=itr.first;
			int x=itr.second;
			mp[x]=temp->data;
			if(temp->left)
				q.push({temp->left,x-1});
			if(temp->right)
				q.push({temp->right,x+1});
		}
	}
	for(auto itr: mp)
		ans.push_back(itr.second);
}
vector<int> bottomView(BinaryTreeNode<int> * root){
      vector<int> ans;
	 if(root ==NULL)
		 return ans;
	solve(root,ans);
	return ans;
    
}
