class Solution {
public:
    int largestInteger(vector<int>& a, int k) {
        int n=a.size();
        if(k>n) return -1;
        vector<int> frq(51,0);
        for(int i=0;i<=n-k;i++){
            vector<int> check(51,0);
            for(int j=i;j<i+k;j++){
                if(!check[a[j]]){ 
                    check[a[j]]=1;
                    frq[a[j]]++;
                }
            }
        }
        for(int i=50;i>=0;i--){
            if(frq[i]==1) return i;
        }
        return -1;
    }
};