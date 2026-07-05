class Solution {
public:
const int mod=1e9+7;
vector<string> b;
int n,m;
vector<vector<pair<int,int>>> dp;
bool isDigit(char c){
    if(c<='9' && c>='0') return true;
    return false;
}
pair<int,int> dpz(int i,int j){
    if(i < 0 || j < 0)
    return {-1,0};
    if(b[i][j] == 'X')
    return {-1,0};
    if(i==0 && j==0)return {0,1};
    if (dp[i][j] != make_pair(-1, -1)) return dp[i][j];
    auto up=dpz(i-1,j);
    auto left=dpz(i,j-1);
    auto upleft=dpz(i-1,j-1);
    long long ways=0;
    int best=max(up.first,max(left.first,upleft.first));
    if(best == -1)
    return dp[i][j] = {-1,0};
    if(up.first==best) ways+=up.second;
    if(upleft.first==best) ways+=upleft.second;
    if(left.first==best) ways+=left.second;
    ways%=mod;
    int val=0;
    if(isDigit(b[i][j])) val=b[i][j]-'0';
    return dp[i][j]={val+best,ways};
}
    vector<int> pathsWithMaxScore(vector<string>& board) {
        b=board;
        m=b.size();
        n=b[0].size();
        dp.assign(101,vector<pair<int,int>>(101,{-1,-1}));
        auto ans=dpz(n-1,m-1);
        if(ans.first==-1) return{0,0};
        return {ans.first,ans.second};
    }
};