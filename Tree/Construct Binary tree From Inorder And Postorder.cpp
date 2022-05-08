// T.C=O(NLOG(N))
// S.C=O(N)



class Solution { 
    TreeNode* build(vector<int>& postorder,int poststart,int postend,vector<int>& inorder,int instart,int ineend,map<int,int>&mp)
    {
        if(poststart>postend || instart>ineend)
            return NULL;
         TreeNode* root=new TreeNode(postorder[postend]);
        int inroot=mp[postorder[postend]];
        int numsleft=inroot-instart;   
        root->left=build(postorder,poststart,poststart+numsleft-1,inorder,instart,inroot-1,mp);
        root->right=build(postorder,poststart+numsleft,postend-1,inorder,inroot+1,ineend,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        TreeNode *root=build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
           return root;
    }
};
