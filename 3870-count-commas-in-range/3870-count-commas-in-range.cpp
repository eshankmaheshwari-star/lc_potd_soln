class Solution {
public:
    int countCommas(int n) {
        string s=to_string(n);
        int m=s.size();
        int cnt=0; 
        if(n<1000) return 0;
        if(1000<=n && n<100000) return (n-999);
        else  return 99999-999+1;

    }
};