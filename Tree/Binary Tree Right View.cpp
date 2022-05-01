// T.C=O(N)
// S.C=O(N)
class Solution { 
private:
    void solve(TreeNode* root, vector<int>&ans)
    { 
       map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0}); 
        while(!q.empty())
        {
            auto itr=q.front();
            q.pop();
            TreeNode* temp=itr.first;
            int x=itr.second;
            mp[x]=temp->val;
            if(temp->left)
                q.push({temp->left,x+1});
            if(temp->right)
                q.push({temp->right,x+1});
        }
        for(auto itr: mp)
            ans.push_back(itr.second);
        
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;  
        solve(root,ans);
        return ans;
        
    }
};
