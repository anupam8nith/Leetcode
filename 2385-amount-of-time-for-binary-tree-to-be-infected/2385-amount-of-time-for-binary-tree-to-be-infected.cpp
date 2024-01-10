class Solution {

public:
    Solution()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);
    }
    
    unordered_map<TreeNode*, vector<TreeNode*>> adj;  
    unordered_set<TreeNode*> visited;  // To track visited nodes
    TreeNode* infected;

    void traverse(TreeNode* root, int start) 
    {
        if (!root) return;

        if (root->val == start) infected = root;

        if (root->left) 
        {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root); // Adding parent to child's adjacency list
        }
        if (root->right) 
        {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root); // Adding parent to child's adjacency list
        }

        traverse(root->left, start);
        traverse(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) 
    {
        if (!root) return 0;

        int ans = 0;
        traverse(root, start);
        queue<TreeNode*> q;
        
        if (infected) 
        {
            q.push(infected);
            visited.insert(infected);
        }

        while (!q.empty()) 
        {
            int sz = q.size();

            for (int i = 0; i < sz; i++) 
            {
                TreeNode* node = q.front();
                q.pop();

                for (auto neighbor : adj[node]) 
                {
                    if (visited.find(neighbor) == visited.end()) 
                    {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            ans++;
        }
        return ans - 1; // Excluding the initial infected node (start)
    }
};
