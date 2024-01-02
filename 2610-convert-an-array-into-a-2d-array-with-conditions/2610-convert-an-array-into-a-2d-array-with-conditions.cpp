class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        vector<vector<int>> ans; unordered_map<int,int> freq; 
        
        for(int& it: nums)freq[it]++;
        
        if(freq.size()==nums.size()) return {{nums.begin(), nums.end()}};
        
        while (!freq.empty()) 
        {
            vector<int> row,toErase;
            
            for (auto& it : freq) 
            {
                row.push_back(it.first); 
                it.second--;
                if (it.second == 0) toErase.push_back(it.first);
            }
            ans.push_back(row);
            
            for (int& key : toErase) freq.erase(key);
        }
        
        return ans;
    }
};