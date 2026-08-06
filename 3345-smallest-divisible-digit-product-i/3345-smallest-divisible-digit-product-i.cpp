class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            string s=to_string(n);
            int pr=1;
            for(char c:s) pr*=(c-'0');
            if(pr%t==0) break;
            else n++;
        }
        return n;
    }
};