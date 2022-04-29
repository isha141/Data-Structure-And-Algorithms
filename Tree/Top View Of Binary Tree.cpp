///T.C= O(NlogN) 
///S>C =O(N)+O(N)
class Solution
{ 
    private:
    void solve(Node *root,vector<int>&ans)
    {
        map<int,int> mp;
        queue<pair<Node *,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto itr=q.front();
                q.pop();
                Node *temp=itr.first;
                int x=itr.second;
                if(mp.find(x)==mp.end())
                mp[x]=temp->data;
                if(temp->left)
                q.push({temp->left,x-1});
                if(temp->right)
                q.push({temp->right,x+1});
            }
        }
        for(auto itr: mp)
        ans.push_back(itr.second);
    }
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
      vector<int>ans;
      if(root==NULL)
      return ans;
      solve(root,ans);
      return ans;
    }

};
