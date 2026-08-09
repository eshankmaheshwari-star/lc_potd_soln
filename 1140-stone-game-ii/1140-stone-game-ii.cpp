class Solution {
public:
vector<int> a,pre;
int n;
vector<vector<int>> dp;
int dpz(int i,int m){
    if(i>=n) return 0;
    if(i+2*m>=n) return dp[i][m]=pre[n]-pre[i];
    if(dp[i][m]!=-1) return dp[i][m];
    int ans=0;
    int remain=pre[n]-pre[i];
    for(int x=1;x<=2*m;x++){
        int opo=dpz(i+x,max(m,x));
        ans=max(ans,remain-opo);
    }
    return dp[i][m]=ans;
}
    int stoneGameII(vector<int>& piles) {
        a=piles;
        n=a.size();
        pre.resize(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+a[i];
        }
        dp.assign(n+1,vector<int>(n+1,-1));
        return dpz(0,1);
    }
};