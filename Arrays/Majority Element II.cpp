// T.C= O(N)+O(N)
// S.C=O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         vector<int> ans;
        int ele1=-1;
        int ele2=-1;
        int count1=0;
        int count2=0;
        for(int itr: nums)
        {
            if(ele1==itr) count1++;
            else if(ele2==itr) count2++;
           else if(count1==0){
                ele1=itr;
                count1=1;
            }
           else if(count2==0){
                ele2=itr;
                count2=1;
            }
            else{  count1--;
                 count2--;
                }
        } 
        count1=count2=0;
        for(auto itr: nums){
            if(ele1==itr)
                count1++;
            else if(ele2==itr)
                count2++;
        } 
        if(count1>nums.size()/3)
            ans.push_back(ele1);
        if(count2>nums.size()/3)
            ans.push_back(ele2);
        return ans;
    }
}; 


//USING BAYER -MOORE VOTING ALGORITHM 
