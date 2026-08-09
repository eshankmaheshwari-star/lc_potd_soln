class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& im, int sr, int sc, int color) {
        int org=im[sr][sc];
        if(org==color) return im;
        int n=im.size();
        int m=im[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        im[sr][sc]=color;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first,c=it.second;
            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && im[nr][nc]==org){
                    q.push({nr,nc});
                    im[nr][nc]=color;
                }
            }
        }
        return im;
    }
};