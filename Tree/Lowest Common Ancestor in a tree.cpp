// T.C=O(N)
// S.C=O(N)


class Solution { 
    private:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL || root==p|| root==q)
            return root;
        TreeNode* left =solve(root->left,p,q);
        TreeNode* right=solve(root->right,p,q);
        if(!left)
            return right;
        if(!right)
            return left;
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
        if(root==NULL)
            return root;
        return solve(root,p,q);
        
    }
};
