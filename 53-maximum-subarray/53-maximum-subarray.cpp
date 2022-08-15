class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long int n = nums.size();
        
        int maxtillnow=INT_MIN, maxendinghere=0;
        
        for(long int i=0;i<n;i++)
        {
         maxendinghere += nums[i];
        
            if(maxtillnow<maxendinghere)
                maxtillnow=maxendinghere;
            if(maxendinghere<0)
                maxendinghere=0;
        }
        return maxtillnow;
    }
    
    
    
};