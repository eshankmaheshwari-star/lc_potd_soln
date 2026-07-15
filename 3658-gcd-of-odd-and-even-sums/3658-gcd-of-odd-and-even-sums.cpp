class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }
    int gcdOfOddEvenSums(int n) {
        int sumodd=n*n,sumeven=n*(n+1);
        return gcd(sumeven,sumodd);
    }
};