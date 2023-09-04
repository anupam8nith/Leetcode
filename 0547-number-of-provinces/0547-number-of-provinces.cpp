class Solution {
public:
    
    void bfs(vector<vector<int>> &adj, vector<int>&vis, int i)
    {
        queue<int> q;
        q.push(i);
        vis[i]=1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node])if(!vis[it])
            {q.push(it);vis[it]=1;}
        }
        
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int ans=0,n =isConnected.size(); vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
          if(isConnected[i][j]==1)
            adj[i].push_back(j);
        
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++)
            if(!vis[i])
            {
                bfs(adj,vis,i);
                ans++;
            }
                
        return ans;
    }
};