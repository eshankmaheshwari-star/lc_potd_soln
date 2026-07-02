// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         int n=g.size();
//         int m=s.size();
//         sort(g.begin(),g.end());
//         sort(s.begin(),s.end());
//         int l=0,r=0;
//         while(l<m){
//             if(g[r]<=s[l]) r++;
//             l++;
//         }
//         return r;
//     }
// };
class Solution {
public:
int n,m;
vector<vector<int>> dp;
vector<int>g,s;
int dpz(int i,int j){
    if(i>=n || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int nt=dpz(i,j+1);
    int t=0;
    if(g[i]<=s[j]) t=1+dpz(i+1,j+1);
    return dp[i][j]=max(t,nt);
}
    int findContentChildren(vector<int>& g1, vector<int>& s1) {
        g=g1;
        s=s1;
        n=g.size();
        m=s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // dp.assign(n,vector<int>(m,-1));
        int r = 0; // child pointer
        for (int l = 0; l < s.size() && r < g.size(); l++) {
            if (s[l] >= g[r]) {
                r++;
            }
        }
        return r;
        //return dpz(0,0);
        // vector<int> next(m+1,0), cur(m+1,0);

        // for(int i=n-1;i>=0;i--){
        //     for(int j=m-1;j>=0;j--){
        //         int nt = cur[j+1];
        //         int t = 0;
        //         if(g[i] <= s[j])
        //             t = 1 + next[j+1];
        //         cur[j] = max(t, nt);
        //     }
        //     next = cur;
        // }
        // return next[0];
    }
};
