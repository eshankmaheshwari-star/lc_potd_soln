class Solution {
public:
    int mod=1e9+7;
    int solve(vector<int>& dp,string s,int i)
    {
        if(i==s.size())
        {
            return 0;
        }
        int temp=0;
        for(char c='a';c<='z';c++)
        {
            temp = (temp+dp[c-'a'])%mod;
        }
        dp[s[i]-'a']=(temp+1)%mod;
        return solve(dp,s,i+1);
    }
    int distinctSubseqII(string s) {
        vector<int> dp(26,0);
        int in= solve(dp,s,0);
        int ans=0;
        for(char c='a';c<='z';c++)
        {
            ans=(ans+dp[c-'a'])%mod;
        }
        return ans;
    }
};