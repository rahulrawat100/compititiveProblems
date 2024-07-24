class Solution {
public:
    long long calc(vector<int>& jD, int i, long long maxt, int d, vector<vector<vector<int>>>& DP)
    {
        if(i==jD.size())
        {
            if(d>1)
               return INT_MAX;
           return maxt;
        }
        if(DP[i][maxt][d] !=-1)
          return DP[i][maxt][d] ;   
        else
        {
            if(d==1)
              return DP[i][maxt][d] = calc(jD, i+1, max(maxt, (long long)jD[i]), d, DP);
            return DP[i][maxt][d] = min(maxt+calc(jD, i+1, jD[i], d-1, DP), calc(jD, i+1, max(maxt, (long long)jD[i]), d, DP));
        }   
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n =jobDifficulty.size();
        if(d>n)return -1;
        vector<vector<vector<int>>> DP(n, vector<vector<int>>(1001, vector<int>(d+1, -1)));
        return calc(jobDifficulty, 1, jobDifficulty[0], d, DP);
    }
};