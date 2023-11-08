class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> um;
        
        for(auto str: strs)
        {
            string temp = str;
            sort(str.begin(),str.end());
            um[str].push_back(temp);
        }
        
        for(auto it: um) ans.push_back(it.second);
        
        return ans;
    }
};