class Solution {
public:
int n,k;
vector<int>dp;
vector<int> a;
// int dpz(int i){
//     if(i==0) return 0;
//     if(dp[i]!=-1) return dp[i];
//     int ans=0;
//     int mx=0;
//     for(int len=1; len<=min(k,i); len++){
//         mx=max(mx,a[i-len]);
//         ans=max(ans,dpz(i-len)+mx*len);
//     }
//     return dp[i]=ans;
// }
    int maxSumAfterPartitioning(vector<int>& arr, int nk) {
        k=nk;
        a=arr;
        n=a.size();
        dp.assign(n+1,0);
        for(int i=1;i<=n;i++){
            int mx=0;
            for(int len=1; len<=min(k,i); len++){
                mx=max(mx,a[i-len]);
                dp[i]=max(dp[i],dp[i-len]+mx*len);
            }
        }
        return dp[n];
    }
};