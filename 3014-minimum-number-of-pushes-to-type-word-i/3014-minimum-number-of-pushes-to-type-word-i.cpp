class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int totalPushes = 0;
        if (n <= 8) {
            return n * 1;
        }
        totalPushes += 8 * 1;
        n -= 8;
        if (n <= 8) {
            return totalPushes + n * 2;
        }
        totalPushes += 8 * 2;
        n -= 8;
        if (n <= 8) {
            return totalPushes + n * 3;
        }
        totalPushes += 8 * 3;
        n -= 8;
        totalPushes += n * 4;
        return totalPushes;
    }
};