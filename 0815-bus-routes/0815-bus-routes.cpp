class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        map<int, vector<int>> mp;

        for (int i = 0; i < routes.size(); ++i) {
            for (const int stop : routes[i]) {
                mp[stop].push_back(i);
            }
        }

        queue<int> q;
        q.push(source);

        int ans = 0;
        vector<bool> visited(routes.size(), false);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                for (const int route : mp[curr]) {
                    if (visited[route]) continue;

                    visited[route] = true;

                    for (const int stop : routes[route]) {
                        if (stop == target) return ans + 1;
                        q.push(stop);
                    }
                }
            }
            ++ans;
        }

        return -1;
    }
};