class Solution {
public:
vector<int> pre;
int precompute(int n){
    if(n<=0) return false;
    if(pre[n]!=-1) return pre[n];
    for(int i=1;i*i<=n;i++){
        if(!precompute(n-i*i)) return pre[n]=1;
    }
    return pre[n]=0;
}
    bool winnerSquareGame(int n) {
        pre.assign(n+1,-1);
        return precompute(n)==1;
    }
};