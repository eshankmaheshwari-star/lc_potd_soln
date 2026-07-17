class Solution {
public:
vector<vector<int>> dp;
vector<int> a;
int n;
int dpz(int i,int j){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MIN;
    for(int k=i;k<=j;k++){
        ans=max(ans,(a[i-1]*a[k]*a[j+1])+dpz(i,k-1)+dpz(k+1,j));
    }
    return dp[i][j]=ans;
}
    int maxCoins(vector<int>& nums) {
        n=nums.size();
        dp.assign(n+2,vector<int>(n+2,0));
        a.push_back(1);
        for(int x:nums) a.push_back(x);
        a.push_back(1);
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int ans=INT_MIN;
                for(int k=i;k<=j;k++){
                    ans=max(ans,(a[i-1]*a[k]*a[j+1])+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n];
    }
};