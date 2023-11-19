class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        map<int, int> mp;
        
        for (int num : nums) mp[num]++;
        
        int ans = 0, mini = mp.begin()->first, maxi = prev(mp.end())->first, cnt = mp[mini];
        
        for (int i = mini + 1; i <= maxi; i++) 
        {
            if (mp.find(i) != mp.end())
            {
                ans += nums.size() - cnt;
                cnt += mp[i];
            }
        }
        
        return ans;
    }
};
