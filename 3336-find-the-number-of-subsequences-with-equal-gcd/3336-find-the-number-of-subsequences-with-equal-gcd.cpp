class Solution {
public:
int n;
vector<int> a;
int dp[200][201][201];
int mod=1e9+7;
int dpz(int i,int g1,int g2){
    if(i<0){
        if(g1>0 && g2>0 && g1==g2) return 1;
        return 0;
    }
    if(dp[i][g1][g2]!=-1) return dp[i][g1][g2];
    long long ans = 0;
        ans = (ans + dpz(i - 1, g1, g2)) % mod;
        int nextg1 = (g1 == 0) ? a[i] : std::gcd(g1, a[i]);
        ans = (ans + dpz(i - 1, nextg1, g2)) % mod;
        int nextg2 = (g2 == 0) ? a[i] : std::gcd(g2, a[i]);
        ans = (ans + dpz(i - 1, g1, nextg2)) % mod;
        return dp[i][g1][g2] = ans;
}
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        n=nums.size();
        a=nums;
        return dpz(n-1,0,0);
    }
};