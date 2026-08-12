class Solution {
public:
    void solve(vector<vector<char>>& g) {
        int cnt=0,n=g.size(),m=g[0].size();
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        queue<pair<int,int>> q;
        int dirr[]={-1,0,1,0};
        int dirc[]={0,1,0,-1};
        for(int i=0;i<m;i++){
            if(g[n-1][i]=='O'){ q.push({n-1,i}); ans[n-1][i]='O';}
            if(g[0][i]=='O'){ q.push({0,i}); ans[0][i]='O';}
        }
        for(int i=0;i<n;i++){
            if(g[i][m-1]=='O'){ 
                ans[i][m-1]='O';
                q.push({i,m-1});}
            if(g[i][0]=='O') {q.push({i,0}); ans[i][0]='O';}
        }
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=it.first+dirr[i];
                    int nc=it.second+dirc[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && g[nr][nc]=='O' && ans[nr][nc]=='X'){
                        ans[nr][nc]='O';
                        q.push({nr,nc});
                    }
                }
            }
            g=ans;
    }
};