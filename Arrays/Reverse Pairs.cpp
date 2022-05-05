// T.C=O(NlogN)+O(N)+O(N)
// S.C=O(N)

class Solution {  
    private:
     
   int counting(vector<int>&nums,int l,int mid,long h)
     { 
        int count=0;
       int j=mid+1;
        while(l<=mid)
        {
            while(j<=h && nums[l]> (long)nums[j]*2)
                j++;
            count+=(j-(mid+1));
            l++;
        }
        return count;
    }
    private:
    int  merge(vector<int>& nums,int *temp,int l,int mid,long h)
    {
        int i=l;
        int k=l;
        int j=mid+1;
       int c= counting(nums,l,mid,h);
        while(i<=mid && j<=h)
        {
            if(nums[i]<=nums[j])
            {
                temp[k++]=nums[i++];
            }
            else
                temp[k++]=nums[j++];
        }
        while(i<=mid) temp[k++]=nums[i++];
        while(j<=h) temp[k++]=nums[j++];
        for(int i=l;i<=h;i++)
            nums[i]=temp[i];
        return c;
    }
    private:
    int  mergesort(vector<int>& nums,int *temp,int l,long h)
    {  
        if(l==h) return 0;
            int mid=(l+h)/2;
            int inv=mergesort(nums,temp,l,mid);
            inv+=mergesort(nums,temp,mid+1,h);
            inv+=merge(nums,temp,l,mid,h);
        return inv;
    }
public:
    int reversePairs(vector<int>& nums) { 
        long n=nums.size();
        int temp[n];
       return mergesort(nums,temp,0,n-1); 
         //return (int)count;
        
    }
};
