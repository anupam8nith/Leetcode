class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        
        vector<int> ans;
        
        unordered_map<int,int> um;
        for(int i=0;i<n;i++) um[nums[i]]=i;
    
        
        for(int i=0;i<n;i++)
        {
            if(um.find(target-nums[i])!=um.end() && um[target-nums[i]]!=i)
            {
                ans.push_back(i);
                ans.push_back(um[target-nums[i]]);
                return ans;
            }
            
        }
        
        
        return ans;
    }
};