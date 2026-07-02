class Solution {
public:
    int tar, n;
    vector<vector<int>> dp;
    vector<int> a;

    int dpz(int idx, int x) {
        if (x == 0) return 0;
        if (idx == 0) return INT_MAX;

        if (dp[idx][x] != -1)
            return dp[idx][x];

        if (x < a[idx - 1])
            return dp[idx][x] = dpz(idx - 1, x);

        int take = INT_MAX;
        int res = dpz(idx, x - a[idx - 1]);
        if (res != INT_MAX)
            take = 1 + res;

        int notTake = dpz(idx - 1, x);

        return dp[idx][x] = min(take, notTake);
    }

    int coinChange(vector<int>& nums, int c) {
        a = nums;
        n = a.size();
        tar = c;

        if (tar == 0) return 0;

        dp.assign(n + 1, vector<int>(tar + 1, -1));

        int ans = dpz(n, tar);
        return (ans == INT_MAX) ? -1 : ans;
    }
};