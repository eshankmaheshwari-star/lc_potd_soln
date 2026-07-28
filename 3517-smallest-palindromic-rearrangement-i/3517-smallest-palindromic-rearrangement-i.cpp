class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        map<char,int>mp;
        for(char c:s) mp[c]++;
        string ans="";
        char o;
        for(auto &it:mp){
            int x=it.second/2;
            while(x--){
                ans+=it.first;
            }
            if(it.second%2!=0) o=it.first;
        }
        string res;
        if(ans.size()*2==n){
            res=ans;
            reverse(ans.begin(),ans.end());
            res+=ans;
        }
        else{
            res=ans;
            reverse(ans.begin(),ans.end());
            res+=o;
            res+=ans;
        }
        return res;
    }
};