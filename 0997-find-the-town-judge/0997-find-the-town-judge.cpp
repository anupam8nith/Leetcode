class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        // ios::sync_with_stdio(false);
        // cin.tie(0);
        
        vector<vector<int>> adj(n+1);
        
       for (auto & t : trust) adj[t[0]].push_back(t[1]);
        
        for(int i=1;i<=n;i++)
            if(adj[i].empty())
            {
                int trustcount=0;
                for(int j=1;j<=n;j++)
                {
                    if(j!=i && find(adj[j].begin(),adj[j].end(),i)!=adj[j].end())
                        trustcount++;
                }
                
                if(trustcount==n-1)
                    return i;
            }
        
        
        return -1;
    }
};