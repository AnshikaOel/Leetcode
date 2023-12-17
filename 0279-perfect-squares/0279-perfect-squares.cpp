class Solution {
public:
    int solve(int &n,vector<int> &dp)
    {
        if(n==0) return 0;
        if(n<0) return INT_MAX;
        if(dp[n]!=-1) return dp[n];
        int mn=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            int a=n-(i*i);
            mn=min(mn,1+solve(a,dp));
        }
        if(mn!=INT_MAX) {
            dp[n]=mn;
        }else
        {dp[n]= 0;}
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};