class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& a, int k) {
        int n=a.size();
        vector<pair<int,int>> pi;
        for(int i=0;i<n;i++){
            pi.push_back({a[i],i});
        }
        sort(pi.begin(),pi.end());
        vector<int> ans(n);
        vector<int>grp_idx,grp_val;
        grp_idx.push_back(pi[0].second);
        grp_val.push_back(pi[0].first);
        for(int i=1;i<n;i++){
            // if(a[i]<=a[i+1]) continue;
            // else{
            //     int it=lower_bound(pi.begin(),pi.end(),a[i]-k)-pi.begin();
            //     if(a[i]-a[pi[it].second]<=k) swap(a[pi[it].second],a[i]);
            // }
            if(pi[i].first-pi[i-1].first<=k){
                grp_idx.push_back(pi[i].second);
                grp_val.push_back(pi[i].first);
            }
            else{
                sort(grp_idx.begin(),grp_idx.end());
                for(int i=0;i<grp_idx.size();i++){
                    ans[grp_idx[i]]=grp_val[i];
                }
                grp_idx.clear();
                grp_val.clear();
                grp_idx.push_back(pi[i].second);
                grp_val.push_back(pi[i].first);
            }
        }
        sort(grp_idx.begin(),grp_idx.end());
                for(int i=0;i<grp_idx.size();i++){
                    ans[grp_idx[i]]=grp_val[i];
                }
        return ans;
    }
};