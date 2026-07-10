class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& a, int maxi, vector<vector<int>>& q) {
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++){
            p.push_back({a[i],i});
        }
        sort(p.begin(),p.end(),[](auto &a,auto &b){
            return a.first<b.first;
        });
        vector<int> pos(n);
        for(int i=0;i<n;i++){
            pos[p[i].second]=i;
        }
        int log = 32 - __builtin_clz(n);
        vector<vector<int>> up(n,vector<int>(log));
        int r=0;
        for(int l=0;l<n;l++){
            if(r<l) r=l;
            while(r+1<n && p[r+1].first-p[l].first<=maxi) r++;
            up[l][0]=r;
        }
        for(int i=1;i<log;i++){
            for(int j=0;j<n;j++){
                up[j][i]=up[up[j][i-1]][i-1];
            }
        }
        vector<int> ans;
        for(auto& it:q){
            int s=pos[it[0]];
            int d=pos[it[1]];
            if(s>d) swap(s,d);
            if(s==d){ 
                ans.push_back(0);
                continue;
            }
            int curr=s;
            int hops=0;
            for(int j=log-1;j>=0;j--){
                if(up[curr][j]<d){
                    curr=up[curr][j];
                    hops+=(1<<j);
                }
            }
            if(up[curr][0]>=d){
                ans.push_back(hops+1);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};