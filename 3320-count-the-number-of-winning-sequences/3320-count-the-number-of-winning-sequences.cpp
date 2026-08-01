class Solution {
public:
const int mod=1e9+7;
string s;
int n;
int dp[1001][2002][4];
const int scoreMat[4][4] = {
    {0,  0,  0,  0}, 
    {0,  0, -1,  1}, 
    {0,  1,  0, -1}, 
    {0, -1,  1,  0} 
};
int mp(char s){
    if(s=='F') return 1;
    if(s=='W') return 2;
    return 3;
}
int dpz(int i,int j,int k){
    if(i==n) return j>0?1:0;
    if(dp[i][j+n][k]!=-1) return dp[i][j+n][k];
    int ans=0;
    for(int cho=1;cho<=3;cho++){
        if(k==cho) continue;
        int sco=scoreMat[cho][mp(s[i])];
        ans=(ans+dpz(i+1,j+sco,cho))%mod;
    }
    return dp[i][j+n][k]=ans;
}
    int countWinningSequences(string ans) {
        s=ans;
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return dpz(0,0,0);
    }
};