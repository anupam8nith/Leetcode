class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        int ans=0;
        unordered_map<int,int> um;
        
        for(auto it: nums)um[it]++;
        
        for(auto it: um) if(it.second>1)
        {
            int val = it.second;
            
            ans += val*(val-1)/2;
        }
        return ans;
        
    }
};