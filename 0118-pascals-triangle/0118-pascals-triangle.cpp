class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         // vector<vector<int>> ans;
        // vector<int> a;
        // a.push_back(1);
        // ans.push_back(a);
        // for(int i=1;i<numRows;i++)
        // {
        //     vector<int> temp;
        //     for(int j=0;j<=i;j++)
        //     {
        //         if(j==0 || j==i)
        //         {
        //             temp.push_back(ans[0][0]);
        //         }
        //         else
        //         {
        //             int a=ans[i-1][j-1]+ans[i-1][j];
        //             temp.push_back(a);
        //         }
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
        vector<vector<int>> output(numRows);
        for(int i=0; i<numRows; i++){
            output[i].resize(i+1, 1);
            for(int j=1; j<i; j++){
                output[i][j] = output[i-1][j-1] + output[i-1][j];
            }
        }
        return output;
    }
};