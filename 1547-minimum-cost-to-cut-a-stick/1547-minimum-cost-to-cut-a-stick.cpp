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
        a=cuts;
        dp.assign(n,vector<int>(n,-1));
        return dpz(0,n-1,0,m);
    }
};