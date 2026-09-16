class Solution {
public:
// maths
//2d vector + presum
//3d vector
typedef long long ll;
const int mod=1e9+7;
int dp[1001][1001][2];
int n,k;
int dpz(int i,int cnt,int draw){
    if(cnt==k) return 1;
    if(n==i+1){
        if(draw && cnt+1==k) return 1;
        return 0;
    }
    if(dp[i][cnt][draw]!=-1) return dp[i][cnt][draw];
    int ans=0;
    if(draw){
        ans=(ans+dpz(i+1,cnt,1))%mod;
        ans=(ans+dpz(i,cnt+1,0))%mod;
    }else{
        ans=(ans+dpz(i+1,cnt,0))%mod;
        ans=(ans+dpz(i+1,cnt,1))%mod;
    }
    return dp[i][cnt][draw]=ans;
}
// ll power(ll base,ll exp){
//     ll res=1;
//     base%=mod;
//     while(exp>0){
//         if(exp&1) res=(res*base)%mod;
//         base=(base*base)%mod;
//         exp/=2;
//     }
//     return res;
// }
// ll fac(ll n){
//     ll ans=1;
//     for(ll i=2;i<=n;i++) ans=(ans*i)%mod;
//     return ans;
// }
    int numberOfSets(int nn, int kn) {
        n=nn;
        k=kn;
        // dp.assign(n+1,vector<int>(k+1,-1));
        memset(dp,-1,sizeof(dp));
        return dpz(0,0,0);
        //return (((fac(n+k-1)*power(fac(n-1-k),mod-2))%mod)*power(fac(2*k),mod-2))%mod;
    }
};