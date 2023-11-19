class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        int ans = 0;map<int, int> mp;
        
        for (int num : nums)mp[num]++;
        
        while (mp.size() > 1) 
        {
            auto it = mp.rbegin();
            int temp = it->first, freq = it->second;
            ans += freq;
            mp.erase(temp);
            
            if (!mp.empty()) 
            {
                it = mp.rbegin(); // Update the iterator
                it->second += freq; 
            }
        }
        
        return ans;
    }
};
