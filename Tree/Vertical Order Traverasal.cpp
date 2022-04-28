/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution { 
    private:
    void level(TreeNode* root,queue<pair<TreeNode *,pair<int,int>>>q,map<int,map<int,multiset<int>>>&mp)
    { 
        while(!q.empty())
        {
            int n=q.size(); 
            for(int i=0;i<n;i++)
            { 
              auto v=q.front();
              q.pop();
              TreeNode *p=v.first;
                int x=v.second.first;
                int y=v.second.second;
                mp[x][y].insert(p->val);
                if(p->left)
                    q.push({p->left,{x-1,y+1}});
                if(p->right)
                    q.push({p->right,{x+1,y+1}});
            }
        } 
        
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}}); 
        map<int,map<int,multiset<int>>>mp;
        level(root,q,mp); 
        for(auto itr: mp)
        {
            vector<int>ds; 
            for(auto itt: itr.second)
            { 
                ds.insert(ds.end(),itt.second.begin(),itt.second.end());
            } 
            ans.push_back(ds);
        }
        
        return ans;
    }
};
