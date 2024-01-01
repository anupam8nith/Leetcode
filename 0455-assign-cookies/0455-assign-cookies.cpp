class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        std::ios::sync_with_stdio(false);cin.tie(NULL);
        
        int count=0, i=0,j=0;
        sort(g.begin(),g.end()); sort(s.begin(),s.end());

       while(i<g.size() && j<s.size())
        {
                if(s[j]>=g[i])
                {
                    count++; i++;
                    if(count==s.size()) return count;
                }
                j++;
        }        
        return count;
    }
};