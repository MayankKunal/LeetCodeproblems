class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        vector<int> nums(10, 0); // To check if all numbers 1-9 are distinct

        // Check all elements in the 3x3 grid
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || nums[val] == 1) {
                    return false; // Number is out of range or already seen
                }
                nums[val] = 1;
            }
        }

        // Check rows, columns, and diagonals sum to 15
        int sum1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int sum2 = grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2];
        int sum3 = grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];
        int sum4 = grid[row][col] + grid[row+1][col] + grid[row+2][col];
        int sum5 = grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1];
        int sum6 = grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2];
        int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int diag2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];

        if (sum1 != 15 || sum2 != 15 || sum3 != 15 ||
            sum4 != 15 || sum5 != 15 || sum6 != 15 ||
            diag1 != 15 || diag2 != 15) {
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};
