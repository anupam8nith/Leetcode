class Solution {
public:
    
    bool solve(int m)
    {
        if(m==3 || m==1)
            return true;
        
        if(m%3==0)
            return solve(m/3);
        else
            return false;
        
        
    }
    bool isPowerOfThree(int n) 
    {
         if(n<0 || n==0)
            return false;
        return solve(n);
    }
};