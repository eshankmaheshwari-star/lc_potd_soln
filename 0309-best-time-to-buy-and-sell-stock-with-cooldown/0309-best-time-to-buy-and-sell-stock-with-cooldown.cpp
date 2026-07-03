class Solution {
public:
vector<int> a;
    int maxProfit(vector<int>& prices) {
        a=prices;
        int n=a.size();
        vector<int> prev(2,0),curr(2,0),prev2(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int pro=0;
                if(j==1) pro+=max(a[i]+prev2[abs(j-1)],prev[j]);
                else pro+=max(-a[i]+prev[abs(j-1)],prev[j]);
                curr[j]=pro;
            }
            prev2=prev;
            prev=curr;
        }
        return prev[0];
    }
};