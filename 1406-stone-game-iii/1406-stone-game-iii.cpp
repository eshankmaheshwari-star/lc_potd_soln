class Solution {
public:
vector<int> dp;
vector<int> a;
int n;
int dpz(int i){
    if(i==n) return 0;
    if(dp[i]!=INT_MIN) return dp[i];
    int maxdiff=INT_MIN;
    int curr=0;
    for(int k=1;k<=3 && i+k-1<n;k++){
        curr+=a[i+k-1];
        int diff=curr-dpz(i+k);
        maxdiff=max(maxdiff,diff);
    }
    return dp[i]=maxdiff;
}
    string stoneGameIII(vector<int>& S) {
        a=S;
        n=a.size();
        dp.assign(n,INT_MIN);
        int ans= dpz(0);
        if(ans>0) return"Alice";
        if(ans<0) return "Bob";
        return  "Tie";
    }
};