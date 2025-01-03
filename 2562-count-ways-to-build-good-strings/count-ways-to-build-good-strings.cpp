class Solution {
public:
    
    int calc(int low, int high, int zero, int one, int l, vector<int>& DP)
    {
        int mod = pow(10, 9)+7;
        if(l>high)
           return 0;
        if(DP[l]!=-1)
           return DP[l];   
        else
        {
            int res=0;
            if(l>=low)
                res++;
            res+=calc(low, high, zero, one, l+zero, DP) + calc(low, high, zero, one, l+one, DP);
            return DP[l]=res%mod;   
        }  

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> DP(high+1, -1);
        return calc(low, high, zero, one, 0, DP);
    }
};