// T.C=O(N)
// S.C=O(N) 

//Using level Order Travessal 


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



//Using PreOrder Travesal 

// T.C =O(N)
// S.C=O(H)
class Solution { 
    private:
    void solve(TreeNode* root,int x,map<int,int>&mp)
    { 
        // right view by using preorder travesal 
        if(root==NULL)
            return ;
        solve(root->left,x+1,mp);
        mp[x]=root->val;
        solve(root->right,x+1,mp);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans;
        map<int,int>mp;
        solve(root,0,mp);
        for(auto itr: mp)
            ans.push_back(itr.second);
        return ans;
    }
};
