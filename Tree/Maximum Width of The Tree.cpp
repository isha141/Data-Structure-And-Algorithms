// T.C=O(N)
// S.C=O(N) 


class Solution { 
    private:
    int width(TreeNode* root)
    {
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        { 
            int mini=INT_MAX;
            int maxi=0;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto itr= q.front();
                q.pop();
                TreeNode* temp=itr.first;
                int x=itr.second;
                mini=min(mini,x);
                maxi=max(maxi,x);
                if(temp->left)
                    q.push({temp->left,(2*long(x-mini)+1)});
                if(temp->right)
                    q.push({temp->right, (2*long(x-mini)+2)});
            }  
            ans=max(ans,maxi-mini+1);
        }
        return ans;
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        return  width(root);
    }
};
