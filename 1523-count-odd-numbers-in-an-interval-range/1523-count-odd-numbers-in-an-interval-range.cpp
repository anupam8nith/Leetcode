class Solution {
public:
    int countOdds(int low, int high) 
    {
        int ans=0;
        
        if(low==high)
        {
            if(low&1)
                return 1;
            else
                return 0;
        }
            
        
        if(low&1)
            ans++;
        if(high&1)
            ans++;
        
       ans+= (high-low-1)/2;
        
        
        if(low%2==0 && (high-low-1)%2==1)
            ans++;
            
        
        return ans;
        
    }
};