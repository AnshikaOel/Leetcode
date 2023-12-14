class Solution {
public:
    
    int breakWord(string s,int i,set<string> &wordDict,vector<int> &dp)
    {
        if(i==s.size()) return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        string temp;
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(wordDict.find(temp)!=wordDict.end())
            {
                if(breakWord(s,j+1,wordDict,dp)) 
                {
                    dp[i]=1;
                    return dp[i];
                }
            }
        }
        dp[i]=0;
        return dp[i];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        // int j=0;
        // int count=0;
        // string a="";
        // while(j<s.size())
        // {
        //     a=a+s[j];
        //     for(int i=0;i<wordDict.size();i++)
        //     {
        //         if(a==wordDict[i]) {
        //             cout<<wordDict[i]<<"-";
        //             count=1;
        //             a="";
        //             // break;
        //         }else{
        //             count=0;
        //         }
        //     }
        //     j++;
        // }
        // if(count==0) return false;
        // return true;
        
        set<string> temp;
        vector<int> dp(s.size(),-1);
        for(auto a: wordDict) temp.insert(a);
        
        return breakWord(s,0,temp,dp);
    }
};