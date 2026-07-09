class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& a, int maxi, vector<vector<int>>& q) {
        vector<int> g(n,0);
        int j=0;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]<=maxi) j++;
            g[i]=j;
        }
        vector<bool> ans;
        for(auto &it:q){
            if(g[it[1]]-g[it[0]]==it[1]-it[0]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};