class Solution {
public:
    long long calc(long long n, long long p, long long d, vector<vector<int>>& DP)
    {
      int mod= pow(10, 9)+7;
      // cout<<n<<"  "<<p<<"  "<<d<<endl;
        if(p<0 ||d<0)
          return 0;
        if(DP[p][d]!=-1)
           return DP[p][d];  
        if(n==0)
          return 1;
        else
           return DP[p][d]=(p*calc(n-1, p-1, d+1, DP)+d*calc(n-1, p, d-1, DP))%mod;
            
    }
    int countOrders(int n) {
      vector<vector<int>> DP(n+1, vector<int>(n+1, -1));
        return calc(2*n, n, 0, DP);
    }
};