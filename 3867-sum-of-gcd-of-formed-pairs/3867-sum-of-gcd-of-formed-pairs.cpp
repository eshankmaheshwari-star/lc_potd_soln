class Solution {
public:
    long long gcdSum(vector<int>& a) {
        int n=a.size();
        vector<int> mx(n),pre(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,a[i]);
            mx[i]=maxi;
            pre[i]=__gcd(a[i],mx[i]);
        }
        sort(pre.begin(),pre.end());
        int l=0,r=n-1;
        long long ans=0;
        while(l<r){
            ans+=(__gcd(pre[l],pre[r]));
            l++;
            r--;
        }
        return ans;
    }
};