class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        long long ans = INT_MAX, n = nums.size();
        
        int idx=-1;
        
        
        // vector<int> left(n,-1), right(n,-1);
        
        long long lsum=0;
        
        // avg from left and from right
        
        long long total = 0;
        
        for(auto x: nums)
            total+=x;
        
        cout<<total<<endl;
        
        for(int i=0;i<=n-2;i++)
        {
            lsum += nums[i];
            
            int temp = abs(lsum/(i+1)- (total-lsum)/(n-1-i));
                
            if(ans>temp)
            {
                ans = temp;
                idx=i;
            }
        }
        
        if(ans>total/n)
            return n-1;
        
        
        return idx;
        
    }
};