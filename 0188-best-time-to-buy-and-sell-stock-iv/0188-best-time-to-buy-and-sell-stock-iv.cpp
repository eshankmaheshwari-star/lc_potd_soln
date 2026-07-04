class Solution {
public:
vector<int> a;
vector<vector<vector<int>>> dp;
int n,k;
int dpz(int idx,bool buy,int alp){
    if(k==alp) return 0;
    if(idx==n) return 0;
    if(dp[idx][buy][alp]!=-1) return dp[idx][buy][alp];
    int pro=0;
    if(buy) pro+=max(a[idx]+dpz(idx+1,!buy,alp+1),dpz(idx+1,buy,alp));
    else pro+=max(-a[idx]+dpz(idx+1,!buy,alp),dpz(idx+1,buy,alp));
    return dp[idx][buy][alp]=pro;
}
    int maxProfit(int kn, vector<int>& prices) {
        k=kn;
        a=prices;
        n=a.size();
        dp.assign(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return dpz(0,false,0);
    }
};