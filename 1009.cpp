class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)
            return 1;
        int i=30;
        for(;i>=0;i--){
            if((N|1<<i)==N){
                break;
            }
        }
        for(;i>=0;i--){
            N^=(1<<i);
        }
        return N;
    }
};
