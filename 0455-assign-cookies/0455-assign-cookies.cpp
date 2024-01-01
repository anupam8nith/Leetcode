class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(),g.end()); multiset<int> ms;
        
        for(int& it: s)ms.insert(it); int ans=0; 
        
        for(int& target: g)
        {
            auto ptr = ms.lower_bound(target);
            if(ptr!=ms.end())
            {
                ans++;ms.erase(ptr);
            }
        }
        
        
        return ans;
    }
};