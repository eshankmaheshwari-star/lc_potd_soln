class Solution {
public:
typedef long long ll;
int dp[1001][1001];
vector<int> a;
int n,k;
ll sum=0;
int mod=1e9+7;
ll dpz(int i,int j){
    if(i==n){ 
        if(j<k) return 1;
        return 0;}
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(j+a[i]<k) ans=(ans+dpz(i+1,j+a[i]))%mod;
    ans=(ans+dpz(i+1,j))%mod;
    return dp[i][j]=ans;
}
    int countPartitions(vector<int>& nums, int nk) {
        a=nums;
        k=nk;
        n=a.size();
        for(int x:a) sum=sum+x;
        if(sum/2<k) return 0;
        memset(dp,-1,sizeof(dp));
        ll total=1;
        for(int i=0;i<n;i++) total=(total*2)%mod;
        return (total - 2*dpz(0,0)+mod)%mod;
    }
};
//10^3 leads us to tle or mle
//totlaprt -wrong part is fast