class Solution 
{
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        if (source == target) return 0;
        int bus_mx = INT_MIN;
        
        for (auto it : routes)
        {
            int x = it.size();
            bus_mx = max(bus_mx, it[x - 1]);
        }
        
        // bus_no -> routes it is contained in
        map<int, vector<int>> mp;
        
        for (int bus = 0; bus <= bus_mx; bus++)
        {
            for (int i = 0; i < routes.size(); i++)
            {
                if (binary_search(routes[i].begin(), routes[i].end(), bus))
                    mp[bus].push_back(i);
            }
        }
        
        // find ans
        queue<int> q; 
        q.push(source); 
        int ans = 0;
        vector<bool> visited(routes.size(), false);
        
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int curr = q.front(); 
                q.pop();
                
                for (auto route : mp[curr])
                {
                    if (visited[route]) continue;
                    visited[route] = true;
                    
                    // for each route no, check whether it has target
                    if (binary_search(routes[route].begin(), routes[route].end(), target)) 
                        return ans + 1;
                    else 
                        for (auto stop : routes[route])
                            q.push(stop);
                }
            }
            ans++;
        } 
        return -1;
    }
};
