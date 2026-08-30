class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int mini_idx=-1,maxi_idx=-1;
        int maxi=INT_MIN,mini=INT_MAX;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(mini>a[i]){
                mini=a[i];
                mini_idx=i;
            }
            if(maxi<a[i]){
                maxi=a[i];
                maxi_idx=i;
            }
        }
        return min({mini_idx+n-maxi_idx+1,n-mini_idx+maxi_idx+1,max(n-maxi_idx,n-mini_idx),max(maxi_idx,mini_idx)+1});
    }
};