class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Special case: only one node

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0); // Degree of each node
        queue<int> leaves; // Queue to store leaf nodes
        
        // Build adjacency list and calculate degree of each node
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        // Enqueue all leaf nodes
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) leaves.push(i);
        }
        
        // Process until there are less than or equal to 2 nodes left
        while (n > 2) {
            int num_leaves = leaves.size();
            n -= num_leaves;
            for (int i = 0; i < num_leaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : adj[leaf]) {
                    if (--degree[neighbor] == 1) leaves.push(neighbor);
                }
            }
        }
        
        // Remaining nodes in the queue are the roots of minimum height trees
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        
        return result;
    }
};
