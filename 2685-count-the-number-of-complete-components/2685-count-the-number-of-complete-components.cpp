class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& vertexCount, int& degreeSum) {
        visited[node] = true;
        vertexCount++;
        degreeSum += adj[node].size(); // Add the degree of the current node
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, vertexCount, degreeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int completeComponentsCount = 0;
        
        // Step 2: Iterate through all nodes to find components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int vertexCount = 0;
                int degreeSum = 0;
                
                // Run DFS to map out the current component
                dfs(i, adj, visited, vertexCount, degreeSum);
                
                // Step 3: Check if the component is complete
                // A complete graph has a total degree sum of V * (V - 1)
                if (degreeSum == (long long)vertexCount * (vertexCount - 1)) {
                    completeComponentsCount++;
                }
            }
        }
        
        return completeComponentsCount;
    }
};