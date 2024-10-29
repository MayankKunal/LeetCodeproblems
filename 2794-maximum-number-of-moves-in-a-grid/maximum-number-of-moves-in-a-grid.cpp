class Solution {
    int help(int row, int col, int n, int m, int prev, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (row >= n || row < 0 || col >= m || grid[row][col] <= prev) return 0;
        if (dp[row][col] != -1) return dp[row][col];

        // Recursive calls for three possible directions
        return dp[row][col] = 1 + max(
            help(row - 1, col + 1, n, m, grid[row][col], grid, dp),
            max(
                help(row, col + 1, n, m, grid[row][col], grid, dp),
                help(row + 1, col + 1, n, m, grid[row][col], grid, dp)
            )
        );
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));  // Fixed dp dimensions
        int ans = 0;

        // Call help function starting from each cell in the first column
        for (int i = 0; i < n; i++) {
            ans = max(ans, help(i, 0, n, m, -1, grid, dp));
        }

        return ans - 1;  // Subtracting 1 to get the number of moves instead of cells visited
    }
};
