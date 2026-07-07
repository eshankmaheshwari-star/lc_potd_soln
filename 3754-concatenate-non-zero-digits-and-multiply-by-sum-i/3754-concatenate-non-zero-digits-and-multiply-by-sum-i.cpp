class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        string ans="";
        long long sum=0;
        for(char c:s){
            if(c!='0') ans+=c;
            sum+=(c-'0');
        }
        if(sum==0) return 0;
        return stoi(ans)*sum;
    }
};