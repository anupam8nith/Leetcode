#pragma GCC optimize("O3")
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) 
    {
        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        sort(nums.begin(),nums.end()); int n = nums.size();
        
        vector<long long> sum(n); sum[0]=nums[0];
        
        for(int i=1;i<n;i++)
            sum[i]=sum[i-1]+nums[i];
        
        for(int i=n-1;i>=2;i--)
            if(sum[i]-nums[i]>nums[i]) 
                return sum[i];
    
        return -1;
    }
};