//T.C-o(5N)
//S.C=O(N) 

vector<int> Solution::repeatedNumber(const vector<int> &A) { 
    vector<int>ans; 
    int xor1=0;
    int x=0;
    int y=0; 
    int n=A.size();
    for(int i=0;i<n;i++)
    xor1=xor1^A[i]; 
  
    for(int i=1;i<=n;i++)
    xor1=xor1^i; 
  // xor1 is a combination of repeat and missing number 
  
    int set_bits=xor1 & ~(xor1-1); 
  //Seperate all the elemnts 
    for(int i=0;i<n;i++)
    {
        if(A[i] & set_bits)
        x=x^A[i]; 
        else y=y^A[i];
    } 
  
    for(int i=1;i<=n;i++)
    {
        if(i & set_bits)
        x=x^i;
        else
        y=y^i;
    }
  
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(x==A[i])
        flag=true;
    } 
    if(flag){
     ans.push_back(x);
     ans.push_back(y);
    }
    
    else{
        ans.push_back(y);
        ans.push_back(x);
    }
    return ans;
}
