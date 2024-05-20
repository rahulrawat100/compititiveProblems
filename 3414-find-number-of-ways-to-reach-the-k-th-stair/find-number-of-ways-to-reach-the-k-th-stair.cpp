class Solution {
public:
    int calc(int curr, int jump, int k, bool canD, int p, unordered_map<int, unordered_map<int, int>>& DP)
    {
        if(curr-k>1)
            return 0;
            
        if(curr-k==1)
        {
            return 1+calc(curr+p-1,jump+1, k, true, 2*p, DP);
        }
        if(curr==k)
        {
            int d =0;
            if(canD)
              d=calc(curr-1, jump, k, false, p, DP);
            return 1+d+calc(curr+p,jump+1, k, true, 2*p, DP);
        }
        if(canD)
           {
              if(DP.find(curr)!=DP.end()&&DP[curr].find(jump)!=DP[curr].end())
                return DP[curr][jump];
           }
        int d =0;
        if(canD)
            d=calc(curr-1, jump, k, false, p, DP);
        int res= d+calc(curr+p,jump+1, k, true, 2*p, DP);
        if(canD)DP[curr][jump]=res;
        return res;

    }
    int waysToReachStair(int k) {
        unordered_map<int, unordered_map<int, int>> DP; 
        return calc(1, 0, k, true, 1, DP);
    }
};