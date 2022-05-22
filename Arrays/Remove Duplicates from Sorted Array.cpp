class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(); 
        int prev=nums[0];
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(nums[k]!=nums[i]){
                nums[++k]=nums[i];
            }
             //   k++;
        }
        return k+1;
    }
};
