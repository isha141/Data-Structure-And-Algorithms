// T.C=O(N)
// S.C=O(N)


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int n=s.size();
        int left=0;
        int right=0; 
        map<char,int>s1;
        while(right<n)
        {
            if(s1.count(s[right]) && s1[s[right]] >=left)
            {
                left=s1[s[right]]+1;
                s1[s[right]]=right;
                right++;
                continue;
            }
            else{
                s1[s[right]]=right;
            }
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};
