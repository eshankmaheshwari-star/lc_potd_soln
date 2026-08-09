class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        int dirr[]={-1,0,1,0};
        int dirc[]={0,1,0,-1};
        int n=g.size(),m=g[0].size();
        int isl=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        function<void(pair<int,int>)> bfs=[&](pair<int,int> i){
            queue<pair<int,int>> q;
            q.push({i.first,i.second});
            vis[i.first][i.second]=1;
            while(!q.empty()){
                auto it=q.front();
                int r=it.first;
                int c=it.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+dirr[i];
                    int nc=c+dirc[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && g[nr][nc]=='1'){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && g[i][j]=='1'){
                    bfs({i,j});
                    isl++;
                }
            }
        }
        return isl;
    }
};
