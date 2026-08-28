class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int cnt=0;
        char mid;
        for(int i=0;i<26;i++){
             if(freq[i]&1){
                 cnt++;
                 mid=i+'a';
             }
             freq[i]/=2;
        }
        if(cnt>1) return "";
        string left = "";
        string prefix = "";
        string ans = "";
        int n = s.size();
        int halflen=n/2;
        if(n==1) return (s>target)?s:"";
        for (int i = 0; i<n/2; i++) {
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string left = prefix+ (char)(c+'a');
                    vector<int> tfreq=freq;
                    tfreq[c]--;
                    for (int j = 0; j < 26; j++) {
                        left += string(tfreq[j], j + 'a');
                    }
                    string right = left;
                    reverse(right.begin(), right.end());
                    ans=left+((n&1)?string(1,mid):"")+right;
                    break; 
                }
            }
            if (freq[target[i] - 'a'] > 0) {
                prefix += target[i];
                freq[target[i] - 'a']--;
            } else {
                break; 
            }
            if(prefix.size()==halflen){
                string right = prefix;
                reverse(right.begin(), right.end());
                string revans=prefix+((n&1)?string(1,mid):"")+right;
                if(revans>target) ans=revans;
            }
        }
        return ans;
    }
};