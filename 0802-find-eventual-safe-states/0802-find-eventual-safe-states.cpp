class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& e) {
        int n=e.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
           for(int x:e[i]) adj[x].push_back(i);
        }
        //vector<int> safe(n,0);
        //vector<int> vis(n,0);//dfsvis(n,0);
        // function<bool(int)> dfs=[&](int i){
        //     vis[i]=1;
        //     dfsvis[i]=1;
        //     for(int x:adj[i]){
        //         if(!vis[x]){
        //             if(!dfs(x)) return false;
        //         }
        //         else if(dfsvis[x]) return false;
        //         else if(!safe[x]) return false;
        //     }
        //     dfsvis[i]=0;
        //     safe[i]=1;
        //     return true;
        // };
        // here adj is for e
        vector<int> outd(n,0);
        for(int i=0;i<n;i++){
            outd[i]=e[i].size();
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!outd[i]){ 
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(int x:adj[n]){
                outd[x]--;
                if(!outd[x]){
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};