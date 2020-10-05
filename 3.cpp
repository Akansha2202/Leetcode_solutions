class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char> q;
        unordered_map<char,bool> mp;
        int m=0,ans=0;
        for(int i=0;s[i];i++){
            if(mp[s[i]]!=0){
                while(q.front()!=s[i]){
                    mp[q.front()]=0;
                    q.pop();
                }
                q.pop();
                q.push(s[i]);
            }
            else{
                q.push(s[i]);
                mp[s[i]]=1;
            }
            m=q.size();
            ans=max(ans,m);
        }
        return ans;
    }
};
