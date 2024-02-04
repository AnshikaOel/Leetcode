class Solution {
public:
    int solve(int lane,vector<int>& obstacles,int j,vector<vector<int>> &dp)
    {
        if(j+2==obstacles.size()){
            return 0;
        }
        if(dp[j][lane]!=-1)return dp[j][lane];
        int ans=INT_MAX;
        if(obstacles[j+1]==lane)
        {  //it has only one option to chnage
            int ans=INT_MAX;
            for(int i=1;i<=3;i++)
            { 
                if(i!=lane && obstacles[j]!=i)
                {
                    
                    ans=min(ans,1+solve(i,obstacles,j+1,dp));
                }
            }
            dp[j][lane]=ans;
            return dp[j][lane];
        }else             // it can go into the same lane 
        {
            dp[j][lane]=solve(lane,obstacles,j+1,dp);
            return dp[j][lane];
        }
        return dp[j][lane];
    }
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return solve(2,obstacles,0,dp);
    }
};