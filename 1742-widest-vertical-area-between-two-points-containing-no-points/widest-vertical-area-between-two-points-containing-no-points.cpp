class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xaxis;

        for(int i=0; i<points.size(); i++)
        {
            xaxis.push_back(points[i][0]);
        }

        sort(xaxis.begin(), xaxis.end());

        int res=0;

        for(int i=1; i<xaxis.size(); i++)
        {
            res=max(res, xaxis[i]-xaxis[i-1]);
        }
        return res;
    }
};