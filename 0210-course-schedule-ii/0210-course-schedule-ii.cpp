class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans;
        int okk=1;
        vector<vector<int>> adj(n);
        for(auto& it:pre){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        function<void(int)> dfs=[&](int i){
            vis[i]=1;
            pathvis[i]=1;
                for(int x:adj[i]){
                    if(!vis[x]){
                        dfs(x);
                        if(!okk) return;
                    }
                    else if(pathvis[x]){
                        okk=0;
                        return ;
                    }
                }
                pathvis[i]=0;
                ans.push_back(i);
        };
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                if(!okk) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};