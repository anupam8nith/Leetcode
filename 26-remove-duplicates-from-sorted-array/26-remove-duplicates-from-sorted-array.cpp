class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        unordered_map<int, int> um;
        
        for(long int i=nums.size()-1;i>=0;i--)
            um[nums[i]]++;
        
        nums.clear();
        
        for(auto x: um)
            nums.push_back(x.first);
        
        sort(nums.begin(), nums.end());
        
        return nums.size();
    }
};