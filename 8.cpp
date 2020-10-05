class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        int base=1;
        long long int n=0;
        int m;
        while(str[i]==' ')i++;
        if(str[i]=='-'){
            m=1;
            i++;
            while(str[i]<='9'&&str[i]>='0'){
                n=n*10-(str[i]-'0');
                if(n<INT_MIN)
                    return INT_MIN;
                else
                    m=n;
                i++;
            }
            // n=n*-1;
        }
        else{
            m=-1;
            if(str[i]=='+')i++;
            while(str[i]<='9'&&str[i]>='0'){
                n=n*10+(str[i]-'0');
                if(n>INT_MAX)
                    return INT_MAX;
                else
                    m=n;
                i++;
            }
        }
        return (int)n;
    }
};
