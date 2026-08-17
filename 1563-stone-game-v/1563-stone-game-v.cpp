class Solution {
public:
vector<int> a;
vector<int> pre;
int n;
vector<vector<int>> dp;
int dpz(int i,int j){
    if(j-i==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int src=0;
    for(int k=i+1;k<j;k++){
        int l=pre[k]-pre[i];
        int r=pre[j]-pre[k];
        if(l>r) src=max(src,r+dpz(k,j));
        else if(r>l) src=max(src,l+dpz(i,k));
        else src=max(src,max(l+dpz(i,k),r+dpz(k,j)));
        // src=min(pre[k]-pre[i],pre[j]-pre[k]);
        // if(pre[k]-pre[i]>pre[j]-pre[k]) src+=dpz(i,k);
        // else src+=dpz(k,j);
    }
    return dp[i][j]=src;
}
    int stoneGameV(vector<int>& st) {
        a=st;
        n=st.size();
        pre.assign(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+a[i];
        }
        dp.assign(n+1,vector<int>(n+1,-1));
        return dpz(0,n);
    }
};