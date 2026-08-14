class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int maxlen=0;
        int l=0,r=0;
        map<int,int> mp;
        while(l<=r && r<n){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};