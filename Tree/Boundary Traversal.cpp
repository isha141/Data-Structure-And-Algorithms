/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void solveleft(TreeNode<int>* root,vector<int> &ans)
{ 
	if(root==NULL)
			return ; 
	if(root->left==NULL && root->right==NULL)
		return ;
		ans.push_back(root->data);
		solveleft(root->left,ans);
		if(root->left==NULL){
			solveleft(root->right,ans);
			return ;
		}
	return ;
} 
void solveleaf(TreeNode<int>* root,vector<int> &ans)
{ 
	if(root==NULL)
		return ;
	if(root->left==NULL && root->right==NULL)
	{
// 		solveleaf(root->left,ans);
		ans.push_back(root->data);
		return ;
	} 
		solveleaf(root->left,ans);
	    solveleaf(root->right,ans);
	return ;
}
void solveright(TreeNode<int>* root,vector<int> &ans,vector<int> &s)
{
	if(root==NULL)
		return ;
	if(root->left== NULL && root->right==NULL)
		return ; 
	s.push_back(root->data);
	if(root->right==nullptr)
		solveright(root->left,ans,s);
	solveright(root->right,ans,s);
	return ;
	
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>ans;
	if(root==NULL)
		return ans; 
	vector<int>s;  
	ans.push_back(root->data);
	if(root->left)
	solveleft(root->left,ans); 
	solveleaf(root->left,ans);
	solveleaf(root->right,ans);
	solveright(root->right,ans,s); 
     for(int i=s.size()-1;i>=0;i--)
	 {
		 ans.push_back(s[i]);
	 } 
// 	for(auto itr: ans)
// 		cout<<itr<<" ";
	return ans;
}
