class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int original = 0;
        for(char c : s)
            original += (c == '1');

        s = "1" + s + "1";

        int n = s.size();
        int ans = original;

        for(int i = 1; i < n - 1; i++) {
            if(s[i] == '1' && s[i - 1] == '0') {
                int j = i;

                while(j < n - 1 && s[j] == '1')
                    j++;

                if(j < n - 1 && s[j] == '0') {

                    int left = i - 1;
                    while(left >= 1 && s[left] == '0')
                        left--;

                    int right = j;
                    while(right < n - 1 && s[right] == '0')
                        right++;

                    int leftZeros = i - left - 1;
                    int rightZeros = right - j;

                    ans = max(ans, original + leftZeros + rightZeros);
                }

                i = j - 1;
            }
        }

        return ans;
    }
};