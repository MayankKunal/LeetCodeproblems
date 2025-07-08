class Solution {
    vector<vector<int>> dp;

    int dfs(int curIndex, int count, int prevEndingTime, vector<vector<int>>& events, int k) {
        if (curIndex == events.size() || count == k) {
            return 0;
        }

        if (prevEndingTime >= events[curIndex][0]) {
            return dfs(curIndex + 1, count, prevEndingTime, events, k);
        }

        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }

        int notTake = dfs(curIndex + 1, count, prevEndingTime, events, k);
        int take = events[curIndex][2] + dfs(curIndex + 1, count + 1, events[curIndex][1], events, k);

        return dp[count][curIndex] = max(take, notTake);
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // sort by start time
        int n = events.size();
        dp.assign(k + 1, vector<int>(n, -1));
        return dfs(0, 0, -1, events, k);
    }
};
