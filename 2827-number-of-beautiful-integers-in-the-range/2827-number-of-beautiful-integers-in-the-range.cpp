class Solution {
public:
    string nstr;
    int k;
    int dp[11][21][21][2][2];
    //intialise everything globally
    int dpz(int idx,int diff,int rem,bool t,bool lz){
        if(idx==nstr.size()) return (diff==0&&rem==0&&!lz)?1:0;
        if (dp[idx][diff + 10][rem][t][lz] != -1) {
            return dp[idx][diff + 10][rem][t][lz];
        }
        int limit=t?nstr[idx]-'0':9;
        int ans=0;
        for(int d=0;d<=limit;d++){
            bool nlz= lz && (d== 0);
            bool nt = t && (d == limit);
            int ndiff=diff;
            if(!nlz){
                ndiff += ((d % 2 == 0) ? -1 : 1);
            }
            int nrem=(rem*10+d)%k;
            ans+=dpz(idx+1,ndiff,nrem,nt,nlz);
        }

        return dp[idx][diff + 10][rem][t][lz]=ans;
    }
    int solve(int n) {
        nstr = to_string(n); 
        memset(dp, -1, sizeof(dp));
        return dpz(0, 0, 0, true, true);
    }
    int numberOfBeautifulIntegers(int low, int high, int K) {
        k=K;
        return solve(high) - solve(low - 1);
    }
};