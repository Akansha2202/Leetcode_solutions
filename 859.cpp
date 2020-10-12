class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length()!=B.length())
            return 0;
        if(A==B){
            vector<bool> b(26,0);
            for(int i=0;A[i];i++){
                if(b[A[i]-'a']){
                    return true;
                }
                b[A[i]-'a']=1;
            }
            return 0;
        }
        int c=0,p,q;
        for(int i=0;A[i];i++){
            if(A[i]==B[i])
                continue;
            if(c>1)
                return false;
            c++;
            if(c==1){
                p=i;
            }
            else{
                if(A[i]==B[p]&&B[i]==A[p]){
                    A[i]=B[i];
                    A[p]=B[p];
                    
                    return A==B;
                }
            }
        }
        if(c==0)
            return false;
        return A==B;
    }
};
