class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> v;
        
        unordered_map <int,int> um;
        
        for(long int i=0;i<nums.size();i++)
        um[nums[i]]=i;
        
        for(long int i=0;i<nums.size();i++)
        {
            if(um.find(target-nums[i])!=um.end() && (i!=um[target- nums[i]]))
            {
                v.push_back(i);
                v.push_back(um[target-nums[i]]);
                break;
            }
        }
        
        return v;
        
    }
};