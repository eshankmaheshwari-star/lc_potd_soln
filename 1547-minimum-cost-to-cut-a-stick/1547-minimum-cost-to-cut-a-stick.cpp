class Solution {
public:
vector<vector<int>> dp;
vector<int> a;
int n,m;
int dpz(int i,int j,int l,int r){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<=j;k++){
        ans=min(ans,dpz(i,k-1,l,a[k])+dpz(k+1,j,a[k],r)+(r-l));
    }
    return dp[i][j]=ans;
}
    int minCost(int nm, vector<int>& cuts) {
        m=nm;
        n=cuts.size();
        sort(cuts.begin(),cuts.end());
        a.push_back(0);
        for(int x:cuts) a.push_back(x);
        a.push_back(m);
        dp.assign(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int ans=INT_MAX;
                for(int k=i;k<=j;k++){
                    ans=min(ans,dp[i][k-1]+dp[k+1][j]+a[j+1]-a[i-1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n];
    }
};