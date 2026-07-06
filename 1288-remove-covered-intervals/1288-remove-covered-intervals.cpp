class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
            sort(in.begin(), in.end(), [](const vector<int>& a, const vector<int>& b) { 
                if(a[0]==b[0]) return a[1]>b[1];
                return a[0] < b[0]; 
            });
        int n=in.size();
        int cnt=n;
        for(int i=0;i<n-1;i++){
            int j=i;
            while(i<n-1 && in[j][0]<=in[i+1][0] && in[j][1]>=in[i+1][1]){
                cnt--;
                i++;
            }
        }
        return cnt;
    }
};