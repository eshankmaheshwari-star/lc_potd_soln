class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        vector<pair<int,int>> ar;
        int n=a.size();
        for(int i=0;i<n;i++){
            ar.push_back({a[i],i});
        }
        sort(ar.begin(),ar.end());
        vector<int> ans(n);
        int k=1;
        for(int i=0;i<n;i++){
            ans[ar[i].second]=k;
            while(i<n-1  && ar[i].first==ar[i+1].first){
                ans[ar[i+1].second]=k;
                i++;
            }
            k++;
        }
        return ans;
    }
};