// T.C=O(N)
// S.C=O(N) 



int Solution::solve(vector<int> &A, int B) { 
    int n=A.size(); 
    int count=0; 
    int xor1=0; 
    map<int,int>mp;
    for(int i=0;i<n;i++)
    { 
        xor1=xor1^A[i];
        if(xor1==B)
        count++;
        if(mp.count(B^xor1))
        {
            count+=mp[B^xor1];
        }
        mp[xor1]++;
    }
    return count;

}

