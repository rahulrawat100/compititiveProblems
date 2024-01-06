class Solution {
public:
    int calc(int i, int j, vector<vector<int>>& DP)
    {
        if(i>=j)
           return 1;
        if(DP[i][j]!=-1)
           return DP[i][j];   
        else
          {
              int res=0;
              for(int k=i; k<=j; k++)
              {
                 res+=calc(i, k-1, DP)*calc(k+1, j, DP);
              }
              return DP[i][j]=res;
          }   
    }
    int numTrees(int n) {
        vector<vector<int>> DP(n+1, vector<int>(n+1, -1));
        return calc(1, n, DP);
    }
};