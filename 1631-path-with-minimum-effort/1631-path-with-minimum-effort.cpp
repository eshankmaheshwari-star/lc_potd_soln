class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        // vector<vector<vector<pair<int,pair<int,int>>>>> adj(n,vector<vector<pair<int,pair<int,int>>>>(m));
        int dirr[]={-1,0,1,0};
        int dirc[]={0,1,0,-1};
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         for(int k=0;k<4;k++){
        //             int nr=i+dirr[k];
        //             int nc=j+dirc[k];
        //             if(nr>=0 && nc>=0 && nc<m && nr<n){
        //                 adj[i][j].push_back({abs(h[i][j]-h[nr][nc]),{nr,nc}});
        //             }
        //         }
        //     }
        // }
        set<pair<int,pair<int,int>>> s;
        s.insert({0,{0,0}});
        while(!s.empty()){
            auto it=* s.begin();
            int dist=it.first;
            int i=it.second.first;
            int j=it.second.second;
            s.erase(it);
            // for(auto alp:adj[i][j]){
            //     int i1=alp.second.first;
            //     int j1=alp.second.second;
            //     if(max(alp.first,dist)<dis[i1][j1]){
            //         if(dis[i1][j1]!=INT_MAX) s.erase({dis[i1][j1],{i1,j1}});
            //         dis[i1][j1]=max(alp.first,dist);
            //         s.insert({dis[i1][j1],{i1,j1}});
            //     }
            // }
            for(int k=0;k<4;k++){
                int nr=i+dirr[k];
                int nc=j+dirc[k];
               if(nr>=0 && nc>=0 && nc<m && nr<n){ 
                    if(max(abs(h[i][j]-h[nr][nc]),dist)<dis[nr][nc]){
                        if(dis[nr][nc]!=INT_MAX) s.erase({dis[nr][nc],{nr,nc}});
                        dis[nr][nc]=max(abs(h[i][j]-h[nr][nc]),dist);
                        s.insert({dis[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};