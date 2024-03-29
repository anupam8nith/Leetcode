class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n==0 || x==1) return 1;
        if(x==0) return 0;
        
        if(n<0)
        {
            x = 1/x;
            n = abs(n);
        }
        
        if(n&1)
            return x*myPow(x*x,n/2);
        else
            return myPow(x*x,n/2);
            
    }
};