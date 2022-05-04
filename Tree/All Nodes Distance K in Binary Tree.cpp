// T.C=O(N)+O(N)
// S.C=O(N)+O(N)+O(N) /// for hashmap,visited map,queue


class Solution { 
    private:
    void parent(TreeNode* root,map<TreeNode*,TreeNode*>&mp)
    {
        if(root==NULL) return ; 
        if(root->left==NULL && root->right==NULL) return ;
        parent(root->left,mp);
        if(root->left)
        mp[root->left]=root; 
        parent(root->right,mp); 
        if(root->right)
        mp[root->right]=root;
    }  
    vector<int> solve(TreeNode* target,int k,vector<int> ans,map<TreeNode *,TreeNode *>mp)
    {
        unordered_map<TreeNode* ,bool >visited;
        queue<TreeNode*>q;
        int d=0;
        q.push(target); 
        visited[target]=true;
        while(!q.empty() && d!=k)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    visited[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right && !visited[temp->right]){
                    visited[temp->right]=true;
                    q.push(temp->right);
                } 
                if(mp[temp] && !visited[mp[temp]])
                {
                    visited[mp[temp]]=true;
                    q.push(mp[temp]);
                }
            }
            d++;
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) { 
        vector<int>ans;
        if(root==NULL)  
            return ans;  
        map<TreeNode*,TreeNode*>mp; 
        parent(root,mp);  
        // for(auto itr: mp)
        // cout<<itr.first->val<<" "<<itr.second->val<<endl;
       return solve(target,k,ans,mp);
    }
};
