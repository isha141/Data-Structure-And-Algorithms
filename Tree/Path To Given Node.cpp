// T.C=O(N)
// S.C=O(N)

bool ways(TreeNode* root,int B,vector<int> &ans)
{
    if(root==NULL){
    return false; 
    }
    ans.push_back(root->val); 
    if(root->val==B)
    {
        return true ;
    }
   bool l=ways(root->left,B,ans);
   bool r=ways(root->right,B,ans);
   if(!l && !r){
    ans.pop_back();  
    return false;
   } 
   else
     return true;
}
vector<int> Solution::solve(TreeNode* root, int B) { 
    vector<int>  ans;
    if(root==NULL)
    return ans;
    ways(root,B,ans);
    return ans;
}
