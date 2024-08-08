class Solution {
public:
    int getpar(vector<int>& par, int x)
    {
        if(par[x]==x)
           return x;
        else
           return getpar(par, par[x]);   
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int,  pair<int, int>>>, greater<pair<int,  pair<int, int>>>> pq;
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<n; j++)
            {
                if(i==j)continue;
                int cost = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                pq.push({cost, {i,j}});
            }
        }

        vector<int> par(n);
        for(int i=0; i<n; i++)
        {
            par[i]=i;
        }

        int count=1;
        int cost=0;
        while(!pq.empty())
        {
            int c = pq.top().first;
            int j= pq.top().second.second;
            int i =pq.top().second.first;
            pq.pop();
            int I = getpar(par, i);
            int J = getpar(par, j);
            if(I==J)continue;
            par[I]=J;
            cost+=c; 
        }
        return cost;
    }
};