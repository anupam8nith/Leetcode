class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {   
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size(), total=0; 
        vector<int> right(n), ans(n);
        
        
        right[0]=nums[0];
        for(int i=1;i<n;i++)right[i]+=right[i-1]+nums[i];
        
        total = accumulate(nums.begin(),nums.end(),0);
        
        
        
        for(int i=0;i<n;i++)
        ans[i]= abs(right[i]-(i+1)*(nums[i])) + abs((total-right[i])-((n-i-1)*nums[i]));
        
        
        return ans;
        
    }
};