class Solution {
    int findParent(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }
    
    bool unionSets(int x, int y, vector<int>& parent, vector<int>& size) {
        int rootX = findParent(x, parent);
        int rootY = findParent(y, parent);
        if (rootX == rootY) return false;
        
        if (size[rootX] >= size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
        return true;
    }
    
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parentAlice(n + 1), parentBob(n + 1), sizeAlice(n + 1, 1), sizeBob(n + 1, 1);
        
        for (int i = 1; i <= n; ++i) {
            parentAlice[i] = i;
            parentBob[i] = i;
        }
        
        int edgesUsed = 0;
        
        // Process type 3 edges first
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (unionSets(edge[1], edge[2], parentAlice, sizeAlice) |
                    unionSets(edge[1], edge[2], parentBob, sizeBob)) {
                    ++edgesUsed;
                }
            }
        }
        
        // Process type 1 edges for Alice
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (unionSets(edge[1], edge[2], parentAlice, sizeAlice)) {
                    ++edgesUsed;
                }
            }
        }
        
        // Process type 2 edges for Bob
        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (unionSets(edge[1], edge[2], parentBob, sizeBob)) {
                    ++edgesUsed;
                }
            }
        }
        
        // Check if both graphs are fully traversable
        int rootAlice = findParent(1, parentAlice);
        int rootBob = findParent(1, parentBob);
        
        for (int i = 1; i <= n; ++i) {
            if (findParent(i, parentAlice) != rootAlice || findParent(i, parentBob) != rootBob) {
                return -1;
            }
        }
        
        return edges.size() - edgesUsed;
    }
};
