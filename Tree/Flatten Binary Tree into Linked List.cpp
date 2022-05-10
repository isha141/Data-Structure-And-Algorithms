// T.C=O(N)
// S.C=O(N)



class Solution {
public: 
    //Iterative Approach 
    void flatten(TreeNode* root) {
        stack<TreeNode* >s; 
        if(root==NULL)
            return ;
        s.push(root); 
        while(!s.empty())
        {
            TreeNode*  curr=s.top();
            s.pop();
            if(curr->right)
                s.push(curr->right);
            if(curr->left)
                s.push(curr->left);
            if(!s.empty())
            {
                curr->right=s.top();
            }
            curr->left=NULL;
        }
    }
};
