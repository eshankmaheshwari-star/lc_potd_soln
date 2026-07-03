class Solution {
public:
int  n,m;
string s1,s2;
vector<vector<int>> dp;
int dpz(int i,int j){
    if (i == n) return m - j;
    if (j == m) return n - i;
    if (dp[i][j] != -1)
            return dp[i][j];

    if(s1[i]==s2[j])   dp[i][j]=dpz(i+1,j+1);
    else dp[i][j]=min(1+dpz(i+1,j),1+dpz(i,j+1));
    return dp[i][j];  
}
    int minDistance(string w1, string w2) {
        s1=w1;
        s2=w2;
        n=s1.size();
        m=s2.size();
        dp.assign(n,vector<int>(m,-1));
        return dpz(0,0);
    }
};