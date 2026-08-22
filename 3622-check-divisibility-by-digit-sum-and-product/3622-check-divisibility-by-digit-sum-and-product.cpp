class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int sum=0,pro=1;
        for(char c:s){
            sum+=(c-'0');
            pro*=(c-'0');
        }
        return !(n%(sum+pro));
    }
};