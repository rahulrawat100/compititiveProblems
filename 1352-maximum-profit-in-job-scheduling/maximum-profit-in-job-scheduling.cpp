class Solution {
public:
    int calc(vector<pair<int, pair<int, int>>>& D, int i, int time, vector<int>& DP, vector<int>& ST)
    {
        if(i>=D.size())
          return 0;
        else if(time<=D[i].first&&DP[i]!=-1)
          return DP[i];  
        else
        {
            int res=INT_MIN;
            if(time<=D[i].first)
               res=max(res, D[i].second.second+calc(D, i+1, D[i].second.first, DP, ST));
            int ind = lower_bound(ST.begin(), ST.end(), time)-ST.begin();
            ind=max(ind, i+1);
            res= max(res, calc(D, ind, time, DP, ST));
            if(time<=D[i].first)
              DP[i]=res;
            return res;     
        }  
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int, pair<int, int>>> D;

        int n = profit.size();
        vector<int> ST;
        for(int i=0; i<n; i++)
        {
            D.push_back({startTime[i], {endTime[i], profit[i]}});
            ST.push_back(startTime[i]);
        }
        vector<int> DP(n, -1);
        sort(D.begin(), D.end());
        sort(ST.begin(), ST.end());
        return calc(D, 0, 0, DP, ST);
    }
};