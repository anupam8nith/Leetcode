class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj,vector<bool> &visited,int start, int end)
    {
        visited[start]=true;
        
        for(auto neighbor: adj[start])
        {
            if(visited[neighbor]==false)dfs(adj,visited,neighbor,end);
        }
        
        return;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        if(source==destination || n==1) return true;
        
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(n+1,false);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(adj,visited,source,destination);
        
        return visited[destination];
        
    }
};