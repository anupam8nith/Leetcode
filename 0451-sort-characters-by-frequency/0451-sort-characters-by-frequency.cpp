class Solution {
public:
    
    string frequencySort(string s) 
    {
        unordered_map<char,int> um;
        
        for(int i=0;i<s.length();i++) um[s[i]]++; //freq stored
        
        string ans="";
        
        vector<pair<int,char>> v;
        
        for(auto ch: um)
        v.push_back({ch.second,ch.first});
        
        sort( v.begin(),v.end(), 
             [](auto a, auto b)
             {return a.first > b.first || (a.first == b.first && a.second > b.second);}
            );
        
        for(auto ch: v)
        {
            while(ch.first--)
                ans+=ch.second;
        }
        
        return ans;
        
    }
};