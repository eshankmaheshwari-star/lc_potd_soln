class Solution {
public:
int n;
vector<vector<int>> dp;
vector<int> a;
int dpz(int i,int j){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int sum=max(a[i]+min(dpz(i+2,j),dpz(i+1,j-1)),a[j]+min(dpz(i,j-2),dpz(i+1,j-1)));
    return dp[i][j]=sum;
}
    bool predictTheWinner(vector<int>& s) {
        a=s;
        n=a.size();
        int sum=0;
        for(int x:s) sum+=x;
        dp.assign(n,vector<int>(n,-1));
        int ans=dpz(0,n-1);
        return (2*ans>=sum);
    }
};