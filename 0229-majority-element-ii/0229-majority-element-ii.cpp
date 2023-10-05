class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n = nums.size();vector<int> ans;
        unordered_map<int,int> um;
        
        for(auto it: nums)
        {
            um[it]++;
            if(um[it]>=(n/3)+1)
            {
                if(ans.empty()) ans.push_back(it);
                else if (ans.back() != it)
                ans.push_back(it);
                
                um.erase(it);
            }
        }
        return ans;
    }
};