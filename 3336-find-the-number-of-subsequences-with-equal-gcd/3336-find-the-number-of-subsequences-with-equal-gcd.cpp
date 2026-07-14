class Solution {
public:
// int n;
// vector<int> a;
// int dp[200][201][201];
// int mod=1e9+7;
// int dpz(int i,int g1,int g2){
//     if(i<0){
//         if(g1>0 && g2>0 && g1==g2) return 1;
//         return 0;
//     }
//     if(dp[i][g1][g2]!=-1) return dp[i][g1][g2];
//     long long ans = 0;
//         ans = (ans + dpz(i - 1, g1, g2)) % mod;
//         int nextg1 = (g1 == 0) ? a[i] : std::gcd(g1, a[i]);
//         ans = (ans + dpz(i - 1, nextg1, g2)) % mod;
//         int nextg2 = (g2 == 0) ? a[i] : std::gcd(g2, a[i]);
//         ans = (ans + dpz(i - 1, g1, nextg2)) % mod;
//         return dp[i][g1][g2] = ans;
// }
//     int subsequencePairCount(vector<int>& nums) {
//         memset(dp, -1, sizeof(dp));
//         n=nums.size();
//         a=nums;
//         return dpz(n-1,0,0);
//     }
int subsequencePairCount(vector<int>& nums) {
        int max_val = 200; 
        int mod = 1e9 + 7;
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> next_dp = dp;

            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;
                    int nextg1 = (g1 == 0) ? x : std::gcd(g1, x);
                    next_dp[nextg1][g2] = (next_dp[nextg1][g2] + dp[g1][g2]) % mod;
                    int nextg2 = (g2 == 0) ? x : std::gcd(g2, x);
                    next_dp[g1][nextg2] = (next_dp[g1][nextg2] + dp[g1][g2]) % mod;
                }
            }
            dp = move(next_dp);
        }
        long long total_pairs = 0;
        for (int g = 1; g <= max_val; ++g) {
            total_pairs = (total_pairs + dp[g][g]) % mod;
        }
        return total_pairs;
    }
};