class Solution {
public:
    int swimInWater(vector<vector<int>>& g) {
        int n=g.size();
        vector<vector<pair<int,int>>> adj(n*n);
        int dirr[]={-1,0,1,0};
        int dirc[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<4;l++){
                    int nr=i+dirr[l];
                    int nc=j+dirc[l];
                    if(nr>=0 && nc>=0 && nc<n && nr<n) adj[i*n+j].push_back({nr*n+nc,g[i][j]});
                }
            }
        }
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        set<pair<int,int>> s;
        vector<int>dis(n*n,INT_MAX);
        dis[0]=g[0][0];
        vector<int>vis(n*n,0);
        s.insert({g[0][0],0});
        while(!s.empty()){
            auto it=*s.begin();
            int node=it.second;
            int dist=it.first;
            s.erase({dist,node});
            if(dist>dis[node]) continue;
            for(auto it2:adj[node]){
                if(max(it2.second,dist)<dis[it2.first]){
                    if(dis[it2.first]!=INT_MAX) s.erase({dis[it2.first],it2.first});
                    dis[it2.first]=max(it2.second,dist);
                    s.insert({dis[it2.first],it2.first});
                }
            }
        }
        return max(dis[n*n-1],g[n-1][n-1]);
    }
};