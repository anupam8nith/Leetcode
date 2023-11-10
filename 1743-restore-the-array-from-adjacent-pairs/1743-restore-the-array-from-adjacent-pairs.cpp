class Solution 
{
public:
    void dfs(int start, int prev, unordered_map<int, vector<int>>& graph, vector<int>& ans) 
    {
        ans.push_back(start);

        for (int neighbor : graph[start]) 
        {
            if (neighbor != prev) dfs(neighbor, start, graph, ans);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        unordered_map<int, vector<int>> graph;
        vector<int> ans;
        // Build the adjacency list
        for (auto& p : adjacentPairs) 
        {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        // Find the start point
        int start = -1;
        for (auto& p : graph) 
        {
            if (p.second.size() == 1) 
            {
                start = p.first;
                break;
            }
        }

        dfs(start, -1, graph, ans);

        return ans;
    }
};
