class Solution {
public:
    
    int solve(vector<int>& days, vector<int>& costs,int i,vector<int> &dp)
    {
        if(i==days.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        // 1 days
        int a=costs[0]+solve(days,costs,i+1,dp);
        
        // 7 days
        int j;
        for(j=i;j<days.size() && days[i]+7>days[j];j++);
        int b=costs[1]+solve(days,costs,j,dp);
        
        // 30 days
        int k;
        for(k=i;k<days.size() && days[i]+30>days[k];k++);
        int c=costs[2]+solve(days,costs,k,dp);
        
        dp[i]= min(a,min(b,c));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return solve(days,costs,0,dp);
    }
};