class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int> um;
        
        for(auto it:nums)um[it]++;
        
        for(auto it: um) if(it.second==1)return it.first;
        
        return 0;
        
    }
};