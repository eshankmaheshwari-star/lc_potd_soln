class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                // We only calculate score at the inner-most "()" pairs
                if (s[i-1] == '(') {
                    // 1 << depth is bitwise for 2^depth
                    score += (1 << depth); 
                }
            }
        }
        
        return score;
    }
};