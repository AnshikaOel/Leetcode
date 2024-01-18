class Solution {
    int solve(vector<vector<char>>& matrix,int i,int j,int &maxi,vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(matrix,i-1,j,maxi,dp);
        int left=solve(matrix,i,j-1,maxi,dp);
        int daigonal=solve(matrix,i-1,j-1,maxi,dp);
        if(matrix[i][j]=='1')
        {
            int ans= 1+min(up,min(left,daigonal));
            maxi=max(ans,maxi);   
            dp[i][j]= ans;
            return dp[i][j];
        }
        dp[i][j]=0;
        return dp[i][j];
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int i=matrix.size()-1,j=matrix[0].size()-1;
        int maxi=0;
        vector<vector<int>> dp(i+1,vector<int>(j+1,-1));
        solve(matrix,i,j,maxi,dp);
        return maxi*maxi;
    }
};