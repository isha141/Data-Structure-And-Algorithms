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
    void vertical(TreeNode *root,map<int,map<int,multiset<int>>>&mp,int x,int y)
    {
        if(root!=NULL)
        {
            mp[x][y].insert(root->val);
            vertical(root->left,mp,x-1,y+1);
            vertical(root->right,mp,x+1,y+1);
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        map<int,map<int,multiset<int>>>mp;
        vertical(root,mp,0,0);
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
