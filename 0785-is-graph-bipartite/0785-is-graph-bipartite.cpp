class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n,0);
        function<bool(int)> bfs=[&](int i){
            queue<int> q;
            vis[i]=1;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int x:adj[node]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x]=-vis[node];
                    }
                    else if(vis[node]==vis[x]) return false;
                }
            }
            return true;
        };
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!bfs(i)) return false;
            }
        }
        return true;
    }
};