//    BY RECURSION WILLGIVE TLE 

// class Solution {
// public:
// int recusrion(vector<int>& coins, int amount)
// {
//     if(amount==0) return 0;
//     if(amount<0) return INT_MAX;
    
//     int mini=INT_MAX;
//     for(int i=0;i<coins.size();i++)
//     {
//         int ans=recusrion(coins,amount-coins[i]);
//         if(ans!=INT_MAX)
//         {
//             mini=min(mini,1+ans);
//         }
//     }
//     return mini;
// }
    
// int coinChange(vector<int>& coins, int amount) {
//     int a=recusrion(coins,amount);
//     if(a==INT_MAX) return -1;
//     return a;
// }

// };

//  MEMOIZATION -- top down approach

class Solution {
public:
int recusrion(vector<int>& coins, int amount,vector<int>& dp)
{
    if(amount==0) return 0;
    if(amount<0) return INT_MAX;
     

    if(dp[amount]!=-1) return dp[amount];
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        int ans=recusrion(coins,amount-coins[i],dp);
        if(ans!=INT_MAX)
        {
            mini=min(mini,1+ans);
        }
    }
    dp[amount]=mini;
    return dp[amount];
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,-1);
    int a=recusrion(coins,amount,dp);
    if(a==INT_MAX) return -1;
    return a;
}
};