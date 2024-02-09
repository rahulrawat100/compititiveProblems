class Solution {
public:
    unordered_map<int, int> DP;
    int numSquares(int n) {
        if(n==0)
          return 0;
        if(DP.find(n)!=DP.end())
          return DP[n];  
        else
          {
              int res=INT_MAX;
              int i = pow(n, 0.5);
              for(; i>=1;i--)
              {
                  res=min(res, 1+numSquares(n-i*i));
              }
              return DP[n]=res;
          }          
    }
};