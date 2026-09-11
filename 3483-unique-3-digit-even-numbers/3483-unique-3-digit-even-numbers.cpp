class Solution {
public:
// int fac(int n){
//     if(n<=1)   return 1;
//     int ans=1;
//     for(int i=2;i<=n;i++) ans*=i;
//     return ans;
// }
    int totalNumbers(vector<int>& d) {
        int n=d.size();
        set<int>s;
        for(int i=0;i<n;i++){
            if(d[i]%2!=0) continue;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue;
                    if(d[k]==0) continue;
                    s.insert(d[k]*100+d[j]*10+d[i]);
                }
            }
        }
        return s.size();
        // int n=d.size();
        // map<int,int> mp;
        // int ans=0;
        // for(int x:d){
        //     mp[x]++;
        // }
        // int x=1;
        // for(auto& it:mp){x*=fac(it.second);}
        // for(int i=0;i<=9;i+=2){
        //     if(mp[i]>0){
        //         ans+=(fac(n-1)/(x/mp[i]));
        //         if(mp[0]){
        //             if(i==0 && mp[0]>=2){
        //                 ans -= fac(n-2) / (x / (mp[0] * (mp[0]-1)));
        //             }
        //             else if(i!=0) ans -= fac(n-2) / (x / (mp[0] * mp[i]));
        //         }
        //     }
        // }
        // return ans;
    }
};