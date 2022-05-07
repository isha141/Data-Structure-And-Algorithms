// T.C=O(N3)
// S.C=O(1)


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans; 
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            int sum1=nums[i];
            int j=i+1;
            while(j<n)
            {
                sum1+=nums[j];
                int left=j+1;
                int right=n-1;
                int sum=target-sum1;
                while(left<right)
                {
                    if(nums[left]+nums[right]==sum)
                    { 
                    ans.push_back({nums[i],nums[j],nums[left],nums[right]});  
                        int temp=nums[left];
                        while(left<right && temp==nums[left])
                            left++;
                        int temp=nums[right];
                        while(right>left && temp==nums[right])
                            right--;
                    }
                    else if(nums[left]+nums[right]<sum) left++;
                    else if(nums[left]+nums[right]>sum) right--;
                }
                while(j+1<n && nums[j]==nums[j+1])    j++;
                 j++;
                sum1=nums[i];
            }
            while(i+1<n && nums[i]==nums[i+1])
                i++;
            i++;
            
        }
        return ans;
    }
};
