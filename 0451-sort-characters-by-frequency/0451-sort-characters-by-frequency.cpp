class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> um;
        for(auto& ch: s)um[ch]++;
        
        vector<pair<int,char>> map;
        
        for(auto it: um)map.push_back({it.second,it.first});

        
        sort(map.begin(),map.end(),[](pair<int,char>& a, pair<int,char>& b)
         {
             if(a.first == b.first)
                 return a.second < b.second; 
             return a.first > b.first;
         }
        );
        
        string ans="";
        
        for(auto& it: map)
            if(it.first != 0)
                while((um[it.second]--)!=0)
                ans += it.second;
        
        return ans;
    }
};