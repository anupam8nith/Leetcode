class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n); // Initialize adjacency list

        // Populate adjacency list
        for (const auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX)); // 2D array to store distances with k stops

        pq.push({0, {src, 0}}); // {cost, {node, stops}}
        dist[src][0] = 0;

        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second.first;
            int stops = pq.top().second.second;
            pq.pop();

            if (node == dst) return cost; // Found destination

            if (stops > k) continue; // Exceeded stop limit

            for ( auto it : adj[node]) {

                int next_node=it.first;
                int next_cost=it.second;
                //int new_cost = cost + next_cost;
                if (cost + next_cost< dist[next_node][stops]) {
                   int  new_cost = cost + next_cost;

                    dist[next_node][stops] = new_cost;
                    pq.push({new_cost, {next_node, stops +1}});
                }
            }
        }

        return -1; // Destination not reachable within k stops
    }
};