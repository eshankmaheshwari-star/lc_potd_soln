// class Solution {
// public:
// const int MAX_K=1e6+1;
//     long long nCr(int n, int r) {
//         if (r < 0 || r > n) return 0;
//         if (r == 0 || r == n) return 1;
//         r = min(r, n - r);
//         long long res = 1;
//         for (int i = 1; i <= r; i++) {
//             res = res * (n - i + 1) / i;
//             if (res >= MAX_K) return MAX_K;
//         }
//         return res;
//     }
//     long long countPermutations(map<char,int>& mp) {
//         int total = 0;
//         for (auto& it:mp) total += it.second;
//         long long res = 1;
//         for (auto& it:mp) {
//             res *= nCr(total, it.second);
//             if (res >= MAX_K) return MAX_K;
//             total -= it.second;
//         }
//         return res;
//     }
//     string smallestPalindrome(string s, int k) {
//         int n=s.size();
//         map<char,int> mp;
//         for(char c:s) mp[c]++;
//         string ans="";
//         string mid="";
//         for(auto& it:mp){
//             if(it.second&1) mid=it.first;
//             it.second/=2;
//         }
//         long long totalpem=countPermutations(mp);
//         if(k>totalpem) return "";
//         n/=2;
//         for(int i=0;i<n;i++){
//             for(auto&it:mp){
//                 if(it.second==0) continue;
//                 it.second--;
//                 long long arg=countPermutations(mp);
//                 if(arg>=k){
//                     ans+=(it.first);
//                     break;
//                 }
//                 else{
//                     k-=arg;
//                     it.second++;
//                 }
//             }
//         }
//         string res=ans;
//         reverse(res.begin(),res.end());
//         return ans+mid+res;
//     }
// };
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    const int MAX_K = 1e6 + 1;

    // Helper to calculate nCr capped at MAX_K
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAX_K) return MAX_K;
        }
        return res;
    }

    // Helper to calculate distinct permutations of the remaining characters
    long long countPermutations(const vector<int>& count) {
        int total = 0;
        for (int c : count) total += c;
        
        long long res = 1;
        for (int freq : count) {
            if (freq == 0) continue;
            res *= nCr(total, freq);
            if (res >= MAX_K) return MAX_K;
            total -= freq;
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        // Step 1: Count character frequencies
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> halfCount(26, 0);
        string mid = "";
        
        for (int i = 0; i < 26; i++) {
            halfCount[i] = freq[i] / 2;
            if (freq[i] % 2 == 1) {
                mid = string(1, (char)('a' + i));
            }
        }

        // Check if k exceeds total possible distinct permutations
        long long totalPerms = countPermutations(halfCount);
        if (k > totalPerms) return "";

        // Step 2: Construct the left half character by character
        int halfLen = s.size() / 2;
        string leftHalf = "";

        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (halfCount[i] == 0) continue;

                // Try picking character 'a' + i
                halfCount[i]--;
                long long arrangements = countPermutations(halfCount);

                if (arrangements >= k) {
                    leftHalf += (char)('a' + i);
                    break; // Picked successfully, move to next position
                } else {
                    k -= arrangements;
                    halfCount[i]++; // Backtrack and try next character
                }
            }
        }
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        return leftHalf + mid + rightHalf;
    }
};