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
    void level(TreeNode* root,queue<TreeNode*>q,vector<vector<int>>&ans)
    {
        q.push(root);
        int count=0;
        while(!q.empty())
        { 
            vector<int>ds; 
            int n=q.size();
            for(int i=0;i<n;i++)
            { 
                TreeNode* temp=q.front();
               q.pop();
                ds.push_back(temp->val);
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(count%2!=0)
                reverse(ds.begin(),ds.end());
            ans.push_back(ds);
            count++;
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { 
         vector<vector<int>>ans;
        if(root==NULL)
            return ans; 
        queue<TreeNode*>q;
        level(root,q,ans);
        return ans;
        
    }
};
