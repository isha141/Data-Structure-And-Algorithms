// T.C=O(N)+O(N)+O(N)
// S.C=O(N)



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        for(auto itr: nums)
            s.insert(itr);
        int count=1;
        int ans=0;
        for(auto itr: nums)
        {
            if(!s.count(itr-1))
            {
                int temp=itr+1;
                while(s.count(temp))
                {
                    temp++;
                }
                ans=max(ans,temp-itr);
            }
        }
        return ans;
    }
};
