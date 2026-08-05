class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {
        vector<int> ans;
        vector<vector<int>> g(n);
        for(auto& e:in) g[e[0]].push_back(e[1]);
        vector<int> vis(n,0);
        function<void(int)> dfs=[&](int u){
            vis[u]++;
            for(int v:g[u]){
                if(!vis[v]) dfs(v);
            }
        };
        dfs(k);
        for(auto& e:in){
            if(!vis[e[0]] && vis[e[1]]){
                for(int i=0;i<n;i++) ans.push_back(i);
                return ans;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};