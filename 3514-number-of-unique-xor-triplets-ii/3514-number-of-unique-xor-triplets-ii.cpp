#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        
        int n = nums.size();
        std::unordered_set<int> pairXors;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXors.insert(nums[i] ^ nums[j]);
            }
        }
        
        std::unordered_set<int> tripletXors;
        for (int px : pairXors) {
            for (int x : nums) {
                tripletXors.insert(px ^ x);
            }
        }
        return tripletXors.size();
    }
};