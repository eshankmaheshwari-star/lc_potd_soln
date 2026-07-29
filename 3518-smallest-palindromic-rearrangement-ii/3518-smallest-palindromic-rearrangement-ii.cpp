class Solution {
public:
const int MAX_K=1e6+1;
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAX_K) return MAX_K;
        }
        return res;
    }
    long long countPermutations(map<char,int>& mp) {
        int total = 0;
        for (auto& it:mp) total += it.second;
        long long res = 1;
        for (auto& it:mp) {
            res *= nCr(total, it.second);
            if (res >= MAX_K) return MAX_K;
            total -= it.second;
        }
        return res;
    }
    string smallestPalindrome(string s, int k) {
        int n=s.size();
        map<char,int> mp;
        for(char c:s) mp[c]++;
        string ans="";
        string mid="";
        for(auto& it:mp){
            if(it.second&1) mid=it.first;
            it.second/=2;
        }
        long long totalpem=countPermutations(mp);
        if(k>totalpem) return "";
        n/=2;
        for(int i=0;i<n;i++){
            for(auto&it:mp){
                if(it.second==0) continue;
                it.second--;
                long long arg=countPermutations(mp);
                if(arg>=k){
                    ans+=(it.first);
                    break;
                }
                else{
                    k-=arg;
                    it.second++;
                }
            }
        }
        string res=ans;
        reverse(res.begin(),res.end());
        return ans+mid+res;
    }
};