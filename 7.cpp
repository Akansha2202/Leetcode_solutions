class Solution {
public:
    int reverse(int x) {
        long int n=0;
        while(x){
                n=n*10+x%10;
            if(n>=INT_MAX||n<=INT_MIN)
            {
                n=0;
                break;
            }
                x=x/10;
            }
        if(x<0){
            return -((int)n);
        }
        return (int)n;
    }
};
