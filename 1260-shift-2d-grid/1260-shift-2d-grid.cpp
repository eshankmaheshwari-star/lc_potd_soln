class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans=grid;
        int n=grid.size();
        int m=grid[0].size();
        k=(k%(n*m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j+k>=m)  ans[(i+((k+j)/m))%n][(j+k)%m]=grid[i][j];
                else ans[i][(j+k)%m]=grid[i][j];
            }
        }
        return ans;
    }
};