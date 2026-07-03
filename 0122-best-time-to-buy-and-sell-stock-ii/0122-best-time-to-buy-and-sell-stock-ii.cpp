class Solution {
public:
vector<int> a;
// vector<vector<int>> dp;
int n;
// int dpz(int idx,bool buy){
//     if(idx==n) return 0;
//     if(dp[idx][buy]!=-1) return dp[idx][buy];
//     int pro=0;
//     if(buy) pro+=max(a[idx]+dpz(idx+1,!buy),dpz(idx+1,buy));
//     else pro+=max(-a[idx]+dpz(idx+1,!buy),dpz(idx+1,buy));
//     return dp[idx][buy]=pro;
// }
    int maxProfit(vector<int>& prices) {
        a=prices;
        n=a.size();
        // dp.assign(n,vector<int>(2,-1));
        // return dpz(0,false);
        vector<int> prev(2,0),curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int pro=0;
                if(j==1) pro+=max(a[i]+prev[abs(j-1)],prev[j]);
                else pro+=max(-a[i]+prev[abs(j-1)],prev[j]);
                curr[j]=pro;
            }
            prev=curr;
        }
        return prev[0];
    }
};