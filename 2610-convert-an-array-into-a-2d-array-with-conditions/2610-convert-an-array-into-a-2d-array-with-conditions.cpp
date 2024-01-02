class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        vector<vector<int>> ans; unordered_map<int,int> freq; 
        
        for(int& it: nums)freq[it]++;
        
        while (!freq.empty()) 
        {
            vector<int> row;
            
            for (auto it=freq.begin();it!=freq.end();) 
            {
                row.push_back(it->first); 
                it->second--;
                if (it->second == 0) it = freq.erase(it);
                else it++;
            }
            ans.push_back(row);
        }
        
        return ans;
    }
};