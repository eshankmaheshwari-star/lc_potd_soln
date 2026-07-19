class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last_idx(26, 0);
        for (int i = 0; i < s.length(); i++) {
            last_idx[s[i] - 'a'] = i;
        }
        
        vector<bool> visited(26, false);
        string result = ""; 
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (visited[ch - 'a']) continue;
            
            while (!result.empty() && result.back() > ch && last_idx[result.back() - 'a'] > i) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            visited[ch - 'a'] = true;
        }
        return result;
    }
};