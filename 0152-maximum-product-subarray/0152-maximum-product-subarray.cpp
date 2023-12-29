// class Solution {
// public:

//     int maxi(vector<int>& nums,int i,int count,int max)
//     {
//         if(i==nums.size())  return max;

//         count=count*nums[i];
//         if(count>max) max=count;
//         return maxi(nums,i+1,count,max);
//     }

//     int maxProduct(vector<int>& nums) {
//         int max=INT_MIN,count=1,ans=INT_MIN;
//         for(int i=0;i<nums.size();i++)
//         {
//             ans=maxi(nums,i,count,max);
//             if(ans>max) max=ans;
//         }
      
//         return max;
//     }
// };

// class Solution {
// public:

//     int maxi(vector<int>& nums,int i,int count,int max,vector<int> &dp)
//     {
//         if(i==nums.size())  return max;

//         if(dp[i]!=-1) return dp[i];
//          if(count==0) count=1;
//         count=count*nums[i];
//         if(count>max) max=count;

//         dp[i]= maxi(nums,i+1,count,max,dp);
//         return dp[i];
//     }

//     int maxProduct(vector<int>& nums) {
//         int max=INT_MIN,count=1,ans=INT_MIN;
//         vector<int> dp(nums.size()+1,-1);
//         for(int i=0;i<nums.size();i++)
//         {
//             ans=maxi(nums,i,count,max,dp);
//             if(ans>max) max=ans;
//         }
      
//         return max;
//     }
// };

class Solution {
public:

    int maxProduct(vector<int>& nums) {
        
        int pre=1,suf=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(pre==0) pre=1;
            if(suf==0) suf=1;
            pre=pre*nums[i];
            suf=suf*nums[nums.size()-1-i];
            ans=max(ans,max(pre,suf));
        }
        return ans;
    }
};