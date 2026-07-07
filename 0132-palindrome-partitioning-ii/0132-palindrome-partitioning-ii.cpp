class Solution {
public:
string s;
int n;
bool ispal(int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    int minCut(string ns) {
        s=ns;
        n=s.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int mincost=INT_MAX;
            for(int j=i;j<n;j++){
                if(ispal(i,j)){
                    int cost=1+dp[j+1];
                    mincost=min(mincost,cost);
                }
            }
            dp[i]=mincost;
        }
        return dp[0]-1;
    }
};