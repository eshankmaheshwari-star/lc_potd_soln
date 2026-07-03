class Solution {
public:
    double power(double x, long long n) {
        double res = 1.0;
        while (n > 0) {
            if (n & 1)
                res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    double myPow(double x, int n) {
        long long N = n;     
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return power(x, N);
    }
};
