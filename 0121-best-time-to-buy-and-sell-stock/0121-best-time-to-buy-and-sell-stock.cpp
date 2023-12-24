class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //  int a=INT_MAX,b;
        // int i,j;
        // for(i=0;i<prices.size();i++)
        // {
        //     if(prices[i]<a)
        //     {
        //         a=prices[i];
        //         j=i;
        //     }
        // }
        // b=a;
        // for(i=j;i<prices.size();i++)
        // {
        //       if(b<prices[i])
        //       {
        //           b=prices[i];
        //       }
        // }
        // return b-a;
        // int min,profit=0;
        // int a;
        // for(int i=0;i<prices.size()-1;i++)
        // {
        //     min=prices[i];
        //     for(int j=i+1;j<prices.size();j++)
        //     {
        //         if(min < prices[j])
        //         {
        //             a=prices[j]-min;
        //             if(profit<a)
        //             {
        //                 profit=a;
        //             } 
        //         }
        //     }
        // }
        // return profit;
        int maxp=0;
        int minsoFar=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            minsoFar=min(minsoFar,prices[i]);
            int profit=prices[i]-minsoFar;
            maxp=max(maxp,profit);
        }
        return maxp;
    }
};