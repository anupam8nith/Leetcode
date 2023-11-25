class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> right(n), left(n), ans(n);
        
        
        right[0]=nums[0];left[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)right[i]+=right[i-1]+nums[i];
        
        for(int i=n-2;i>=0;i--)left[i]+=left[i+1]+nums[i];
        
        
        for(int i=0;i<n;i++)
        ans[i]= abs(right[i]-(i+1)*(nums[i])) + abs(left[i]-((n-i-1)*nums[i])) - nums[i];
        
        
        return ans;
        
    }
};