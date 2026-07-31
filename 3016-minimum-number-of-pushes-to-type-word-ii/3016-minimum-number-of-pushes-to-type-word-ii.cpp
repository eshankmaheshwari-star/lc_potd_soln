class Solution {
public:
    int minimumPushes(string w) {
        vector<int> hash(26,0);
        for(char c:w)  hash[c-'a']++;
        sort(hash.begin(),hash.end());
        int ans=0,x=8;
        for(int i=25;i>=0;i--){
            if(hash[i]==0) continue;
            ans+=(hash[i]*(x/8));
            x++;
        }
        return ans;
    }
};