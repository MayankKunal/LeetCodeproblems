class Solution {
    vector<vector<int>> makeAdj(int n, vector<vector<int>>& edges) {
        vector<vector<int>> Adj(n); // Initialize adjacency list with size n
        for (auto edge : edges) {
            Adj[edge[0]].push_back(edge[1]);
            Adj[edge[1]].push_back(edge[0]);
        }
        return Adj;
    }

    pair<int, int> bfs(vector<vector<int>>& Adj, int src) {
        queue<int> q;
        unordered_map<int, bool> vis;
        q.push(src);
        vis[src] = true;
        int level = 0;
        int farthestNode = 0;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int node = q.front();
                q.pop();
                farthestNode = node;
                for (auto adjNode : Adj[node]) {
                    if (!vis[adjNode]) {
                        q.push(adjNode);
                        vis[adjNode] = true;
                    }
                }
            }
            if (!q.empty()) {
                level++;
            }
        }
        return {farthestNode, level};
    }

    int findDiameter(vector<vector<int>>& Adj) {
        auto [farthestNode, _] = bfs(Adj, 0); // First BFS to find the farthest node
        auto [_, diameter] = bfs(Adj, farthestNode); // Second BFS to find the diameter
        return diameter;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1; // Number of nodes in the first tree
        int n2 = edges2.size() + 1; // Number of nodes in the second tree

        vector<vector<int>> Adj1 = makeAdj(n1, edges1);
        vector<vector<int>> Adj2 = makeAdj(n2, edges2);

        int d1 = findDiameter(Adj1);
        int d2 = findDiameter(Adj2);

        // Calculate the new diameter after merging
        int newDia = ((d1 + 1) / 2 + (d2 + 1) / 2 + 1);

        return max({d1, d2, newDia});
    }
};
