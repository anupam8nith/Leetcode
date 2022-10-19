class Solution {
public:
    bool static cmp(pair<int,string> a, pair<int,string> b )
    {
        if(a.first==b.first)
            return a.second<b.second;
            
            return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> um;
        
        for(auto s: words)
        um[s]++;
        
        vector<pair<int, string>> v;
        
        for(auto p:um)
            v.push_back({p.second,p.first});
        
        
        sort(v.begin(),v.end(),cmp);
        
        vector<string> ans;
        
        for(int i=0;i<k;i++)
        ans.push_back(v[i].second);
        
        return ans;
        
    }
};