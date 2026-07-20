#include <string>
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){ 
            if(mat[i][0]=='1') ans=1;
            dp[i][0]=mat[i][0]-'0';
        }
        for(int j=0;j<m;j++){ 
            if(mat[0][j]=='1') ans=1;
            dp[0][j]=mat[0][j]-'0';
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]=='0') dp[i][j]=0;
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};