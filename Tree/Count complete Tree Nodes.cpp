T.C=O(log(n))2
S.C=O(1)

class Solution {
    private:
    int findleft(TreeNode* root)
    {
        int c=0;
        while(root)
        {
            c++;
            root=root->left;
        }
        return c;
    }
    int findright(TreeNode* root)
    {
        int c=0;
        while(root)
        {
            c++;
            root=root->right;
        }
        return c;
    }
public:
    int countNodes(TreeNode* root) { 
        if(root==NULL) return 0;
        int lh=findleft(root);
        int rh=findright(root);
        if(lh==rh) return (1<<lh)-1;

        return  1+ countNodes(root->left)+countNodes(root->right);
        
    }
};
