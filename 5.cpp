/*Longest palindromic substring
Problem Number : 5
*/ 

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        string ans="";
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i>j)
                    continue;
                if(i==j)
                {
                    dp[i][j]=1;
                }
                else
                {
                    if(s[i]!=s[j])
                    {
                        dp[i][j]=0;
                    }
                    else
                    {
                        if(j-i<=1)
                        {
                            dp[i][j]=1;
                        }
                        else
                        {
                            
                                dp[i][j]=dp[i+1][j-1];
                           
                        }
                    }
                }
                
                if(dp[i][j] && ans.length()<(j-i+1))
                {
                    ans=s.substr(i,(j-i+1));
                }
            }
        }
        
        return ans;
        
    }
};
