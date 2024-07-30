class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        bool ins=false;
        if(n==0)
           return {newInterval};
        for(int i=0; i<n; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(newInterval[1]<start || newInterval[0]>end)
            {
                if(newInterval[1]<start&&!ins)
                {
                   res.push_back(newInterval);
                   ins=true;
                }
                res.push_back({start, end});
            }
            else
            {
                newInterval[0]=min(start, newInterval[0]);
                newInterval[1]=max(end, newInterval[1]);
            }
               if(i==n-1&&!ins)
                {
                    res.push_back(newInterval);
                }
             
        }
        
        return res;
    }
};