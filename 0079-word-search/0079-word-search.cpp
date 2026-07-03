class Solution {
public:
int n,m,len;
vector<vector<char>> a;
vector<vector<int>> dp;
string s;
bool dfs(int i,int j,int k){
    if(i<0||j<0||j>=n||i>=m) return false;
    if(s[k]!=a[i][j]) return false;
    if(k+1==len) return true;
    char temp=a[i][j];
    a[i][j]='#';
    bool found=dfs(i+1,j,k+1)||dfs(i,j+1,k+1)||dfs(i-1,j,k+1)||dfs(i,j-1,k+1);
    a[i][j]=temp;
    return found;

}
    bool exist(vector<vector<char>>& na, string ns) {
        a=na;
        s=ns;
        n=a[0].size();
        m=a.size();
        len=s.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,0)) return true;
            }
        }
        return false;
    }
};