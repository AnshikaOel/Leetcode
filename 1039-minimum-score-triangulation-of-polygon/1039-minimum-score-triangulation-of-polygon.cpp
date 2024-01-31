class Solution {
public:
    
//     i=1,j=2,k=3
    
    int solve(vector<int>& values,int i ,int j ,vector<vector<int>>&dp)
{
    // BASE CASE CHECK IF THE FIRST ELEMENT AND LAST ELEMENT ARE TOGETHER OR NOT 
    if(i+1==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
       return dp[i][j];
    int ans = INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        ans = min(ans , values[i]*values[j]*values[k]+solve(values,i,k,dp)+solve(values, k, j , dp));
    }
    dp[i][j]=ans;
    return dp[i][j];

}
    
    
    
//     int solve(vector<int>& values,int i,int k,vector<vector<int>> dp)
//     {
//        if(i+1==k){
//            return 0;
//        } 
        
//         if(dp[i][k]!=-1){
//             return dp[i][k];
//         }
//         int ans=INT_MAX;
//         for(int j=i+1;j<k;j++)
//         {
//             // dp[i][j]=solve(values,i,j,dp);
//             // dp[j][k]=solve(values,j,k,dp);
//             // dp[i][k]=min(dp[i][k],values[i]*values[j]*values[k]+dp[i][j]+dp[j][k]);
//             ans=min(ans,values[i]*values[j]*values[k]+solve(values,i,j,dp)+solve(values,j,k,dp));
           
//         }
//         dp[i][k]=ans;
//         return dp[i][k];
//     }
    
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
     return solve(values,0,n-1,dp);   
    }
};