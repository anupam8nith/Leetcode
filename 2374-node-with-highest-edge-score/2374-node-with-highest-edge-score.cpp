class Solution {
public:
    int edgeScore(vector<int>& edges) 
    {
        unordered_map<int,long long> mp;
        
        for(int i=0;i<edges.size();i++)
            if(mp.count(edges[i])==0)
            mp[edges[i]]=i;
            else mp[edges[i]]+=i;
        
        int ans=0; long long mx=0;
        for(auto it: mp)
            if(mx==it.second)
                ans=min(ans,it.first);
            else if(mx<it.second)
                {ans=it.first;mx=it.second;}
        
        return ans;
        
    }
};