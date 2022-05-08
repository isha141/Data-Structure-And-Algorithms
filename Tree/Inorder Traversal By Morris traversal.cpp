T.C=O(N)
S.C=0(1)
  
  
  
class Solution { 
    //Morris Traversal 
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        TreeNode* cur=root;
        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
               in.push_back(cur->val);
                cur=cur->right;
            } 
            else{ 
                TreeNode* temp=cur->left;
                while(temp->right!=NULL && temp->right!=cur)
                {
                    temp=temp->right;
                }
                if(temp->right==NULL)
                {
                    temp->right=cur;
                    cur=cur->left;
                }
                else{ 
                    in.push_back(cur->val);
                    temp->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return in;
    }
};
