class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> Adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            Adj[u].push_back({v, time});
            Adj[v].push_back({u, time});
        }

        // Step 2: Initialize Dijkstra's Algorithm
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0); 
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {distance, node}

        // Step 3: Process the queue
        while (!pq.empty()) {
            auto [curDist, node] = pq.top();
            pq.pop();

            if (curDist > dist[node]) continue; // Skip outdated entries

            for (auto [adjNode, time] : Adj[node]) {
                long long newDist = curDist + time;

                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node]; // Reset path count
                    pq.push({newDist, adjNode});
                } else if (newDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD; // Add more ways
                }
            }
        }

        return ways[n - 1]; // Shortest path count to destination
    }
};
