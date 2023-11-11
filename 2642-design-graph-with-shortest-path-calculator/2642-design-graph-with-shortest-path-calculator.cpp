class Graph 
{
    private:
    int n;
    vector<vector<int>> adjmat;
    
    public:
  
    Graph(int n, vector<vector<int>>& edges) 
    {
        this->n = n;
        this->adjmat = vector<vector<int>>(n, vector<int>(n, 1e9));
        for (int i=0; i<n; i++) 
            adjmat[i][i] = 0; // dist from same to same is 0
        for (auto edge: edges) 
            adjmat[edge[0]][edge[1]] = edge[2]; // adjmat[from][to] = cost
        
        for (int k=0; k<n; k++) 
        {
            for (int i=0; i<n; i++) 
            {
                for (int j=0; j<n; j++) 
                {
                    adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
                }
            }
        }
    }
    void addEdge(vector<int> edge) 
    {
        // floyd alg only the the recently added edge {from, to, cost}
        // find out whether adjmat[i][from] + adjmat[to][j] + cost is minimum than current
        for (int i=0; i<n; i++) 
        {
            for (int j=0; j<n; j++) 
            {
                adjmat[i][j] = min(adjmat[i][j],adjmat[i][edge[0]]+adjmat[edge[1]][j]+edge[2]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) 
    {
        if (adjmat[node1][node2]==1e9) return -1;
        return adjmat[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */