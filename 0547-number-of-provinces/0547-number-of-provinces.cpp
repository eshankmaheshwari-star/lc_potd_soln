class Solution {
public:
    int findCircleNum(vector<vector<int>>& isc) {
        int n=isc.size();
        vector<int> vis(n+1,0);
        function<void(int)> dfs=[&](int i){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                vis[node]=1;
                for(int j=0;j<n;j++){
                    if(isc[node-1][j] && !vis[j+1]){
                        vis[j+1]=1;
                        q.push(j+1);
                    }
                }
            }
        };
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};