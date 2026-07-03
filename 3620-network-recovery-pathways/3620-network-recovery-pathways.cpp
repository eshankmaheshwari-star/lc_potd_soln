#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    // Changed signature to 3 arguments to match your environment's requirement
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = (int)online.size(); // Infer n from the size of the online vector
        
        vector<vector<pair<int, int>>> adj(n);
        set<int> cost_set;
        
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], c = edge[2];
            if (online[u] && online[v]) {
                adj[u].push_back({v, c});
                cost_set.insert(c);
            }
        }
        
        vector<int> sorted_costs(cost_set.begin(), cost_set.end());
        int low = 0, high = (int)sorted_costs.size() - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAchieve(n, adj, sorted_costs[mid], k)) {
                ans = sorted_costs[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }

private:
    bool canAchieve(int n, const vector<vector<pair<int, int>>>& adj, int threshold, long long k) {
        vector<long long> dp(n, -1);
        dp[0] = 0;
        
        vector<int> in_degree(n, 0);
        for (int u = 0; u < n; ++u) {
            for (auto& edge : adj[u]) {
                if (edge.second >= threshold) {
                    in_degree[edge.first]++;
                }
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            if (dp[u] != -1) {
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int cost = edge.second;
                    if (cost >= threshold) {
                        if (dp[v] == -1 || dp[v] > dp[u] + cost) {
                            dp[v] = dp[u] + cost;
                        }
                    }
                }
            }
            
            for (auto& edge : adj[u]) {
                if (edge.second >= threshold) {
                    if (--in_degree[edge.first] == 0) q.push(edge.first);
                }
            }
        }
        
        return dp[n - 1] != -1 && dp[n - 1] <= k;
    }
};