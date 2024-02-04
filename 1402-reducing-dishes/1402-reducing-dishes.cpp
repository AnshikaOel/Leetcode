class Solution {
public:
    
    int solve(vector<int>& satisfaction,int i,int m,vector<vector<int>> &dp){
        
        if(i==satisfaction.size()){
            return 0;
        }
        
        if(dp[i][m]!=-1){
            return dp[i][m];
        }
        // take
         int take=((m)*satisfaction[i])+(solve(satisfaction,i+1,m+1,dp));
        //  skip
        int skip=solve(satisfaction,i+1,m,dp);
        
        dp[i][m]=max(take,skip);
        return dp[i][m];
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        if(satisfaction[n-1]<0){
            return 0;
        }
        int ans=0,m=INT_MIN;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<satisfaction.size();i++)
        {
            ans=max(ans,solve(satisfaction,i,1,dp));
        }
        return ans;
    }
};