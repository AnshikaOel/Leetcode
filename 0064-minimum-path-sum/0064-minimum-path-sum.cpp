class Solution {
public:
    int path(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &dp)
    {
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(i==grid.size() || j==grid[0].size()) return 1000;

        if(dp[i][j]!=-1) return dp[i][j];

        int a=path(grid,i+1,j,dp);
        int b=path(grid,i,j+1,dp);
        dp[i][j]= grid[i][j]+min(a,b);
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),(vector<int>(grid[0].size(),-1)));
        return path(grid,0,0,dp);
    }
};