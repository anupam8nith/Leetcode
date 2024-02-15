class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) 
    {
        int n =nums.size(),o=0,e=0;
        
        while(!(nums[o]&1))o++; while(nums[e]&1)e++;
        
        vector<int> ans(n);int i=0;
        
            while(i<n)
            {
                ans[i++]=nums[e++]; ans[i++]=nums[o++];
                while(o<n && !(nums[o]&1))o++; while(e<n && nums[e]&1)e++;
            }
        return ans;
    }
};