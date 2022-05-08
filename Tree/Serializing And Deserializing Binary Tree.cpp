// T.C=O(N)
// S.C=O(N)


class Codec { 
private:
    TreeNode* solve(int ind,string &data)
    {   
      if(data.size()==0)
          return NULL; 
       stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        { 
            TreeNode* temp=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
            {
                temp->left=NULL;
            }
            else{
                TreeNode* leftnode=new TreeNode(stoi(str));
                temp->left=leftnode;
                q.push(temp->left);
            }
            getline(s,str,',');
            if(str=="#")
            {
                temp->right==NULL;
            }
            else
            {
                TreeNode* rightnode=new TreeNode(stoi(str));
                temp->right=rightnode;
                q.push(temp->right);
            }
        }
      return root;
    }
public:
    string serialize(TreeNode* root) {
       string s="";
        if(root==NULL)
            return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
               TreeNode* temp=q.front();
                q.pop(); 
                if(temp==NULL)
                {  s+='#';
                 s+=','; }
                else{
                    s+=to_string(temp->val);
                s+=',';
                }
                if(temp!=NULL){
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
        } 
        cout<<s<<" ";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
           return NULL;
        return solve(0,data);
    }
};
