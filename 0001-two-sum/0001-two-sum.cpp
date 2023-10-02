class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        int n = nums.size();
        
        unordered_map<int,int> um;
        for(int i=0;i<n;i++) um[nums[i]]=i;
    
        
        for(int i=0;i<n;i++)
        {
            if(um.find(target-nums[i])!=um.end() && um[target-nums[i]]!=i)
            return {um[target-nums[i]],i};
            
        }
        
        
        return {};
    }
};