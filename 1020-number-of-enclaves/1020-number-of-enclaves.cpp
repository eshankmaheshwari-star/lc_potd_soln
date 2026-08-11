class Solution {
public:
    int numEnclaves(vector<vector<int>>& g) {
        int cnt=0,n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1) cnt++;
            }
        }
        int dirr[]={-1,0,1,0};
        int dirc[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        function<int(int,int)> bfs=[&](int i,int j){
            int cnt=1;
            queue<pair<int,int>> q;
            q.push({i,j});
            vis[i][j]=1;
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=it.first+dirr[i];
                    int nc=it.second+dirc[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && g[nr][nc] && !vis[nr][nc]){
                        cnt++;
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
            return cnt;
        };
        int bound1=0;
        for(int i=0;i<m;i++){
            if(!vis[0][i] && g[0][i]){
                bound1+=bfs(0,i);
            }
            if(!vis[n-1][i] && g[n-1][i]){
                bound1+=bfs(n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && g[i][0]){
                bound1+=bfs(i,0);
            }
            if(!vis[i][m-1] && g[i][m-1]){
                bound1+=bfs(i,m-1);
            }
        }
        return cnt-bound1;
    }
};