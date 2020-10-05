class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length(),res=0;
        if(n==0)
            return 0;
        vector<int> dp(n,0);
        for(int i=1;s[i];i++){
            if(s[i]==')'){
                if(i-1-dp[i-1]>=0&&s[i-1-dp[i-1]]=='('){
                    dp[i]=dp[i-1]+2;
                    if(i-dp[i]>=0)
                        dp[i]+=dp[i-dp[i]];
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
