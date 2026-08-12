class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& g) {
        int cnt=0,n=g.size(),m=g[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        int dirr[]={-1,0,1,0};
        int dirc[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=it.first+dirr[i];
                    int nc=it.second+dirc[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && g[nr][nc] && ans[nr][nc]==-1){
                        ans[nr][nc]=1+ans[it.first][it.second];
                        q.push({nr,nc});
                    }
                }
            }
        return ans;
    }
};