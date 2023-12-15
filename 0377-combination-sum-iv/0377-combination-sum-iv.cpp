class Solution {
public:
    
    int combination(vector<int>& nums, int target,vector<int> &dp)
    {
        if(target==0) 
        {
            return 1;
        }
        if(target<0) {
            return 0;
        }
        if(dp[target]!=-1) return dp[target];
        
        int count=0;
        for(int j=0;j<nums.size();j++)
        {
           count+= combination(nums,target-nums[j],dp);
        }
        dp[target]=count;
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return  combination(nums,target,dp);
    }
};