class Solution {
public:
    int longestSubsequence(vector<int>& a) {
        int n=a.size();
        int xr=-1;
        int okk=0;
        for(int i=0;i<n;i++){
            if(a[i]) okk=1;
            if(xr==-1) xr=a[i];
            else xr^=a[i];
        }
        if(!okk) return 0;
        if(xr==0) return n-1;
        return n;
    }
};