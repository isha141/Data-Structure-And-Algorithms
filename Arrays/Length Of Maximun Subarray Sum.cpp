// T.C=0(N)
// S.C=0(N)

int maxLen(vector<int>&A, int n)
    {   
        // Your code here 
        map<int,int>mp; 
        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
             if(sum==0)
            {
                maxi=max(maxi,i+1);
            }
            else{
            if(mp.count(sum))
            {
                maxi=max(maxi,i-mp[sum]);
            } 
            else
             mp[sum]=i;
            }
            
        } 
        // for(auto itr: mp)
        // cout<<itr.first<<" "<<itr.second<<endl;
        return maxi;
    }
