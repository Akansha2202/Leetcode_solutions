class Solution {
public:
    bool isMatch(string s, string p) {
        
        
        int i=0,j=0,n=s.length(),m=p.length();
        int prev=0,curr=-1;
        while(i<n){
            if(j<m && p[j]=='*'){
                prev=i;
                curr=j++;
            }
            else if(j<m && (s[i]==p[j]||p[j]=='?')){
                i++;
                j++;
            }
            else if(curr>=0){
                i=++prev;
                j=curr+1;
            }
            else
                return false;
        }
        while(j<m && p[j]=='*')
            j++;
        return j==m;
        
    }
};