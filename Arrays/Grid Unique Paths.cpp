// T.C=O(M*N)
// S.C=0(M*N)

///BETTER APPROACH 
class Solution { 
private:
    int ways(int i,int j,int m,int n,vector<vector<int>>&dp)
    { 
        if(i>m || j>n)
            return 0;
        if(i==m && j==n)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=ways(i+1,j,m,n,dp) + ways(i,j+1,m,n,dp);
        return dp[i][j];
        
    }
public:
    int uniquePaths(int m, int n) { 
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return ways(0,0,m-1,n-1,dp);
    }
};
 

//OPTIMIZED APPROACH 
// T.C=O(M-1) OR O(N-1)
// S.C=O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int total=m+n-2;
      double ans=1; 
        int r=m-1;
        for(int i=1;i<=r;i++)
        {
            ans=ans*(total-r+i)/i;
        }
        return (int) ans;
    }
};
