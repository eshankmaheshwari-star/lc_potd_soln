class Solution {
public:
string s;
int k,n;
vector<vector<int>> pre;
vector<vector<vector<int>>> dp ;
int calc(int i,int j){
    int len=j-i+1;
    int mincost=len;
    for(int d=1;d<len;d++){
        if(len%d==0){
            int cost=0;
            for (int offset = 0; offset < d; ++offset) {
                int left = i + offset;
                int right = j - d + 1 + offset;
                while (left < right) {
                    if (s[left] != s[right]) {
                        cost++;
                    }
                    left += d;
                    right -= d;
                }
            }
            mincost=min(mincost,cost);
        }
    }
    return mincost;
}

int dpz(int i, int j, int a) {
        if (i == n) {
            if (a == k) return 0;
            return 1e9;
        }
        if (j == n) {
            if (a == k - 1 && (n - i) >= 2) return pre[i][n - 1];
            return 1e9;
        }

        if (dp[i][j][a] != -1) return dp[i][j][a];
        int ans = dpz(i, j + 1, a);
        if (a < k - 1 && (j - i + 1) >= 2) {
            ans = min(ans, pre[i][j] + dpz(j + 1, j + 1, a + 1));
        }

        return dp[i][j][a] = ans;
}
    int minimumChanges(string ns, int nk) {
        s=ns;
        k=nk;
        n=s.size();
        pre.assign(n,vector<int>(n,0));
        dp.assign(n,vector<vector<int>>(n,vector<int>(k,-1)));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pre[i][j]=calc(i,j);
            }
        }
        return dpz(0,0,0); 
    }
};