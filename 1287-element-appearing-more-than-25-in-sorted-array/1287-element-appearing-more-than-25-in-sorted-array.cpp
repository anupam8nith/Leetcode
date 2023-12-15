class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        unordered_map<int,int> um; int n = arr.size();
        
        for(auto& it: arr) {um[it]++; if(um[it]>n/4) return it;}
        
        return -1;
    }
};