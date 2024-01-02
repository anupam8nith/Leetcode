class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) \
    {
        int cnt[201] = {}, max_cnt = 0;
        for (auto n : nums)
            max_cnt = max(max_cnt, ++cnt[n]);

        vector<vector<int>> res(max_cnt);
        for (int i = 0; i < 201; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                res[j].push_back(i);
        
        return res;
    }
};