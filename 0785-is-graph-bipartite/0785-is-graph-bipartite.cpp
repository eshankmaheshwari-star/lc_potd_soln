class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n,0);
        // function<bool(int)> bfs=[&](int i){
        //     queue<int> q;
        //     vis[i]=1;
        //     q.push(i);
        //     while(!q.empty()){
        //         int node=q.front();
        //         q.pop();
        //         for(int x:adj[node]){
        //             if(!vis[x]){
        //                 q.push(x);
        //                 vis[x]=-vis[node];
        //             }
        //             else if(vis[node]==vis[x]) return false;
        //         }
        //     }
        //     return true;
        // };
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         if(!bfs(i)) return false;
        //     }
        // }
        function<bool(int,int)> dfs=[&](int i,int j){
            vis[i]=j;
                for(int x:adj[i]){
                    if(!vis[x]){
                        if(!dfs(x,-j)) return false;
                    }
                    else if(vis[i]==vis[x]) return false;
                }
            return true;
        };
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(i,1)) return false;
            }
        }
        return true;
    }
};