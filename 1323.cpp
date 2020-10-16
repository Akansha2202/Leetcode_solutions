class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        
        for(int i=0;s[i];i++)
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        cout<<s;
        int k=stoi(s);
        return (int)k;
    }
};
