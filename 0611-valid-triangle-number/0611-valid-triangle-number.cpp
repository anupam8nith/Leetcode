class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end()); int n= nums.size(), ans=0;
        
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int idx = lower_bound(nums.begin()+j+1,nums.end(),nums[j]+nums[i]) - nums.begin();
                ans+=idx-j-1;
            }
        return ans;
    }
};