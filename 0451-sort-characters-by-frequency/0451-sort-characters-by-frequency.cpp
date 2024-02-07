#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> freq;
        
        for(auto ch: s)freq[ch]++;
        
        using int_char=pair<int, char>;
        vector<int_char>v;
        
        for(auto ele: freq)
                v.push_back({ele.second,ele.first});
        
        sort(v.begin(),v.end(),greater<int_char>());
        
        string ans ="";
        
        for(auto [n,c] :v)
           ans+= string(n,c);
        
        return ans;
        
    }
};