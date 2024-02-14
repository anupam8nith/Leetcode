#pragma GCC optimize ("O3")
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int sz = nums.size(),p=0,n=0; vector<int> ans;
        
        while(nums[p]<0)p++; while(nums[n]>0)n++;
        
        while(ans.size()!=sz)
        {
            ans.push_back(nums[p++]);ans.push_back(nums[n++]);
            while(p<sz && nums[p]<0)p++; while(n<sz && nums[n]>0)n++;
        }
        
        return ans;
    }
};