// T.C=O(N)
// S.C=O(N)

class Solution { 
    private:
    TreeNode* buildtree(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,map<int,int>&mp)
    {
        if(prestart>preend || instart>inend) return NULL; 
        TreeNode *root=new TreeNode(preorder[prestart]);
        int inroot=mp[root->val];
        int numsleft=inroot-instart;
        root->left=buildtree(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,mp); 
         root->right=buildtree(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,mp);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
        map<int,int>mp;
       for(int i=0;i<inorder.size();i++)
       {
           mp[inorder[i]]=i;
       }
       TreeNode* root=buildtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};
