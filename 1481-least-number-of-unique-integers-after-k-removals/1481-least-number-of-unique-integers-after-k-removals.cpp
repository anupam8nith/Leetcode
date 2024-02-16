class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        unordered_map<int, int> um;
        for (auto it : arr) um[it]++;
        
        vector<pair<int,int>> freq;
        
        for(auto it: um)freq.push_back({it.second,it.first});
        
        sort(freq.begin(),freq.end());
        
        int rmv=0;
        for (auto it : freq)
        {
            if (it.first > k) 
                return um.size();
            k -= it.first;
            um.erase(it.second);
        }
        
        return um.size();
    }
};