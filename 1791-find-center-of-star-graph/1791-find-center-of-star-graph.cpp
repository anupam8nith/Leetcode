class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        unordered_map<int, vector<int>> um;
        
        for(auto it: edges)
        {
            um[it[0]].push_back(it[1]);
            um[it[1]].push_back(it[0]);
        }
        
        for(auto it: um)if(it.second.size()==edges.size())return it.first;
        
        return -1;
    }
};
