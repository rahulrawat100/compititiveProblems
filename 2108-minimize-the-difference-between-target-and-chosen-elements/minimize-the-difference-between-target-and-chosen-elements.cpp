class Solution {
public:
    int calc(vector<vector<int>>& mat,int i,int sum, int target, vector<vector<int>>& DP)
    {
        if(i==mat.size())
           return abs(target-sum);
        if(target<0)
           return INT_MAX;
        if(DP[i][sum]!=-1)
          return DP[i][sum];  
        else
        {
            int res=INT_MAX;
            for(int j=0; j<mat[i].size(); j++)
            {
                res =min(res, calc(mat, i+1, sum+mat[i][j], target, DP));
                if(res==0)break;
            }
            return DP[i][sum]=res;
        }   
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<vector<int>> DP(mat.size(), vector<int>(5000, -1));
        return calc(mat, 0, 0, target, DP);
    }
};