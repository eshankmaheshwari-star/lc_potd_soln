class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        int n=a.size();
        if(n<3) return n;
        int pos = 31 - __builtin_clz(n);
        pos++;
        int val = 1 << pos;
        return val;
    }
};