class Solution {
public:
vector<int> a;
// vector<vector<int>> dp;
int n;
    int maxProfit(vector<int>& prices, int fee) {
        a=prices;
        n=a.size();
        vector<int> prev(2,0),curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int pro=0;
                if(j==1) pro+=max(a[i]+prev[abs(j-1)]-fee,prev[j]);
                else pro+=max(-a[i]+prev[abs(j-1)],prev[j]);
                curr[j]=pro;
            }
            prev=curr;
        }
        return prev[0];
    }
};