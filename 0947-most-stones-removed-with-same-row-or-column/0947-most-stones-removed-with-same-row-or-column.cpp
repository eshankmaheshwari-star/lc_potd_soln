class Solution {
public:
    int removeStones(vector<vector<int>>& st) {
        int maxir=-1,maxic=-1;
        for(auto it:st){
            maxir=max(maxir,it[0]);
            maxic=max(maxic,it[1]);
        }
        int n=maxir+1,m=maxic+1;
        int N=m+n;
        vector<int> par(N+1);
        for (int i = 0; i <= N; i++) par[i] = i;
        vector<int> size(N + 1, 1);
        function<int(int)> find = [&](int i) {
            if (par[i] == i) return i;
            return par[i] = find(par[i]);
        };
        function<void(int, int)> un = [&](int i, int j) {
            int pi = find(i);
            int pj = find(j);
            if (pi == pj) return;
            if (size[pi] > size[pj]) {
                size[pi] += size[pj];
                par[pj] = pi;
            } else {
                size[pj] += size[pi];
                par[pi] = pj;
            }
        };
        for(auto& it:st){
            int nr=it[0];
            int nc=it[1]+n;
            un(nr,nc);
        }
        set<int> compo;
        for(auto& it:st) compo.insert(find(it[0]));
        return st.size()-compo.size();
    }
};