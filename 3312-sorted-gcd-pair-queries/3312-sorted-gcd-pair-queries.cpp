class Solution {
public:
typedef long long ll;
    vector<int> gcdValues(vector<int>& a, vector<long long>& qq) {
        int n=a.size(),maxi=*max_element(a.begin(),a.end());
        vector<int> freq(maxi+1,0);
        vector<ll> cnt(maxi+1,0);
        vector<ll> pre(maxi+1,0);
        vector<ll> exact(maxi+1,0);
        for(int x:a) freq[x]++;
        for(int i=1;i<=maxi;i++){
            for(int d=i;d<=maxi;d+=i){
                cnt[i]+=freq[d];
            }
        }
        for(int i=maxi;i>0;i--){
            ll p=cnt[i]*(cnt[i]-1)/2;
            for(int m=2*i;m<=maxi;m+=i) p-=exact[m];
            exact[i]=p;
        }
        for(int d=1;d<=maxi;d++){
            pre[d]=pre[d-1]+exact[d];
        }
        vector<int> ans;
        for (long long q : qq) {
            auto it = upper_bound(pre.begin(), pre.end(), q);
            int index = it - pre.begin();
            ans.push_back(index);
        }
        return ans;
    }
};