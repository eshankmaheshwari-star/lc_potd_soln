class Solution {
public:
    static const int mod=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int>digits,pos;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                digits.push_back(s[i]-'0');
                pos.push_back(i);
            }
        }
        int m=digits.size();
        vector<long long>prefSum(m+1,0),prefNum(m+1,0),pow10(m+1,1);
        for(int i=1;i<=m;i++) pow10[i]=pow10[i-1]*10%mod;
        for(int i=0;i<m;i++){
            prefSum[i+1]=(prefSum[i]+digits[i])%mod;
            prefNum[i+1]=(prefNum[i]*10+digits[i])%mod;
        }
        vector<int>ans;
        for(auto &q:queries){
            int l=q[0],r=q[1];
            auto it1=lower_bound(pos.begin(),pos.end(),l);
            auto it2=upper_bound(pos.begin(),pos.end(),r);
            if(it1==it2){
                ans.push_back(0);
                continue;
            }
            int L=it1-pos.begin();
            int R=it2-pos.begin()-1;
            long long sum=(prefSum[R+1]-prefSum[L]+mod)%mod;
            long long num=(prefNum[R+1]-1LL*prefNum[L]*pow10[R-L+1]%mod+mod)%mod;
            ans.push_back(1LL*sum*num%mod);
        }
        return ans;
    }
};