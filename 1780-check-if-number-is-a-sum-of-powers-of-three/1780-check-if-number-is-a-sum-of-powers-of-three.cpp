class Solution {
public:
    bool checkPowersOfThree(long int n) 
    {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        
        if(n==1 || n==3)
            return true;
        if(n==2 )
            return false;
        
        long int val = 1;
        
        while(val<=n)
            
        {
            val*=3;
        }
        val/=3;
        
        if(val==n)
            return true;
        
       
        
        
        if(n>=2*val)
            return false;
        else
            
            n=n-val;
        
        return checkPowersOfThree(n);
    }
};