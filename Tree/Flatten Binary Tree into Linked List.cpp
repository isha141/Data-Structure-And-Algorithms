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


//RECURSIVE APPROACH   
// T.C=O(N)
// S.C=0(N)
    
class Solution {
public: 
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) { 
        if(root==NULL)
        return ;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};


//MORRIS TRAVERSAL 
// T.C=O(N)
// S.C=O(1)

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return ;
        while(root!=NULL)
        {
            if(root->left!=NULL)
            {
               TreeNode* temp=root->left;
                while(temp->right!=NULL)
                    temp=temp->right;
                temp->right=root->right; 
                root->right=root->left;  
                root->left=NULL;
            }
            root=root->right;
        }
    }
};
