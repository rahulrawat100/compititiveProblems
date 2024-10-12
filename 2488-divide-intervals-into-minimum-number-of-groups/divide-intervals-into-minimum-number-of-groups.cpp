class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b)
    {
        return a[1]<b[1];
    }
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int> pq;
        int n = intervals.size();
        int res=0;
        for(int i=0; i<n; i++)
        {
            while(!pq.empty()&&(-pq.top())<intervals[i][0])
            {
                pq.pop();
            }
            pq.push(-intervals[i][1]);
            //cout<<pq.size()<<endl;
            res=max(res, (int)pq.size());
        }
        return res;
    }
};