class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int n = intervals.size();

        for(int i=0; i<n; i++)
        {
            int a=intervals[i][0];
            int b= intervals[i][1];

            int x =  newInterval[0];
            int y=  newInterval[1];

            if(b<x)
              res.push_back({a, b});
            else if(a>y)
            {
                res.push_back({x, y});
                newInterval[0]=INT_MAX;
                newInterval[1]=INT_MAX;
                res.push_back({a,b});
            }
            else
            {
                newInterval[0]=min(a, x);
                newInterval[1]=max(b, y);
            }  
        }
        if(newInterval[0]!=INT_MAX)
           res.push_back(newInterval);
       return res;    
    }
};