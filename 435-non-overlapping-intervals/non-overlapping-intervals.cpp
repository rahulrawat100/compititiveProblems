class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int res=0;
        for(int i=1; i<n; i++)
        {
            if(end>intervals[i][0])
            {
                res++;
                end = min(end, intervals[i][1]);
            }
            else
            {
                end = intervals[i][1];
            }
        }
        return res;
    }
};