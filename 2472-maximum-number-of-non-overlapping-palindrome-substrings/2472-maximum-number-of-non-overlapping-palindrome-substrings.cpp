class Solution {
public:
string s;
int n,k;
vector<int> dp;
vector<vector<bool>> pal;
bool ispal(int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int solve(int i){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];

    int ans = solve(i-1);

    for(int j=i-k+1;j>=0;j--){
        if(pal[j][i]){
            ans=max(ans,1+solve(j-1));
        }
    }
    return dp[i]=ans;
}
    int maxPalindromes(string ns, int nk) {
        s=ns;
        k=nk;
        n=s.size();
        dp.assign(n,-1);
        pal.assign(n,vector<bool>(n,false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2)
                        pal[i][j] = true;
                    else
                        pal[i][j] = pal[i + 1][j - 1];
                }
            }
        }
        return solve(n-1);
    }
};