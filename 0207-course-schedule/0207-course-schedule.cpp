class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto& it:pre){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        function<bool(int)> dfs=[&](int i){
            vis[i]=1;
            pathvis[i]=1;
                for(int x:adj[i]){
                    if(!vis[x]){
                        if(dfs(x)) return true;
                    }
                    else if(pathvis[x]) return true;
                }
                pathvis[i]=0;
            return false;
        };
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i)) return false;
            }
        }
        return true;
    }
};