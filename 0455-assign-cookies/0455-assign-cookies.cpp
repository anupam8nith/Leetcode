class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        multiset<int> ms;
        
        for(int& it: s)ms.insert(it); int ans=0; 
        
        for(int& target: g)
        {
            if(ms.empty()) return ans;
            
            auto ptr = ms.lower_bound(target);
            if(ptr!=ms.end()){ans++;ms.erase(ptr);}
        }
        
        return ans;
    }
};