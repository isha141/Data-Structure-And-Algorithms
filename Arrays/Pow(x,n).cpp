// T.C=O(logN)
// S.C=O(1)


class Solution {
public:
    double myPow(double x, long n) {
        double ans=1.0; 
        bool flag=0;
        if(n<0)
        {
            flag=1;
            n=-1*n;
        }
        while(n!=0)
        {
            if (n%2==0)
            {
                x=x*x;
                n=n/2;
            }
            else{
                ans=ans*x;
                n=n-1;
            }
        }
        if(flag)
            ans=double(1/ans);
        return ans;
    }
};
