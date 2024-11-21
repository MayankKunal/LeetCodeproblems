class Solution {
    void markDirection(int i, int j, int n, int m, vector<vector<int>>& grid, int dirX, int dirY) {
        // Base conditions: stop if out of bounds, hit a wall, or another guard
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1 || grid[i][j] == 2)
            return;

        // Mark the cell as guarded if it's unoccupied
        if (grid[i][j] == 0)
            grid[i][j] = 3;

        // Recurse in the same direction
        markDirection(i + dirX, j + dirY, n, m, grid, dirX, dirY);
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Initialize the grid
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Place guards and walls on the grid
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2; // Guard
        }
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 1; // Wall
        }

        // Mark cells guarded by each guard using recursion
        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];
            markDirection(x - 1, y, m, n, grid, -1, 0); // Up
            markDirection(x + 1, y, m, n, grid, 1, 0);  // Down
            markDirection(x, y - 1, m, n, grid, 0, -1); // Left
            markDirection(x, y + 1, m, n, grid, 0, 1);  // Right
        }

        // Count unguarded and unoccupied cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};
