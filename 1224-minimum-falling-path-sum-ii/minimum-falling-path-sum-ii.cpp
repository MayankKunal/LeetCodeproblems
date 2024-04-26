#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    int help(int row, int prev, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (row == n) return 0; // Base case: reached the last row

        if (dp[row][prev] != -1) return dp[row][prev]; // Return memoized value if available
        
        int ans = INT_MAX;
        for (int i = 0; i < m; ++i) {
            if (i == prev) continue; // Skip if choosing the same column in adjacent rows
            ans = min(ans, grid[row][i] + help(row + 1, i, n, m, grid, dp));
        }

        return dp[row][prev] = ans; // Memoize the result and return
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1)); // Memoization table
        
        int ans = INT_MAX;
        for (int i = 0; i < m; ++i) {
            ans = min(ans, grid[0][i] + help(1, i, n, m, grid, dp)); // Start from the first row
        }
        return ans;
    }
};
