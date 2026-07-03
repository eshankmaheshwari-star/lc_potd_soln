class Solution {
public:
    static const int mod = 1e9 + 7;

    long long power(long long x, long long n) {
        long long res = 1;
        while (n > 0) {
            if (n & 1)
                res = (res * x) % mod;
            x = (x * x) % mod;
            n >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;  // even indices
        long long odd  = n / 2;        // odd indices

        long long x = power(5, even);
        long long y = power(4, odd);

        return (x * y) % mod;
    }
};
