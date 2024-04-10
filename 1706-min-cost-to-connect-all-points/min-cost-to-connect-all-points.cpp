
class Solution {
public:
    int getpar(vector<int>& par, int x)
    {
        if(par[x]==x)
           return x;
        else
           return par[x]=getpar(par, par[x]);   
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, pair<int, int>>> pq;

        int n = points.size();

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                pq.push({-dist, {i, j}});
            }
        }
        vector<int> par(n);
        for(int i=0; i<n; i++)
        {
            par[i]=i;
        }
        int count=1;
        int res=0;
        while(count<n&&!pq.empty())
        {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int I = getpar(par, i);
            int J = getpar(par, j);
            if(I!=J)
            {
                par[I]=J;
                count++;
                res-=pq.top().first;
            }
            pq.pop();
        }
        return res;
    }
};