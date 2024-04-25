class Solution {
private:
    int solve(int ind, string &s, int prev, int k, vector<vector<int>> &dp) {
        if(ind == -1) {
            return 0;
        }
        
        if(dp[ind][prev+1] != -1)
            return dp[ind][prev+1];
        
        int take = 0;
        int ch = s[ind] - 'a';
        
        if (prev == -1 or abs(ch - prev) <= k) {
            take = solve(ind - 1, s, ch, k, dp) + 1;
        }
        
        int notTake = solve(ind - 1, s, prev, k, dp);
        return dp[ind][prev+1] = max(take, notTake);
    }
public:
    
    int longestIdealString(string s, int k) {
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(27, -1)); // 27 because space for 26 alphabets and one more for '0';
        
        return solve(n - 1, s, -1, k, dp);
    }
};