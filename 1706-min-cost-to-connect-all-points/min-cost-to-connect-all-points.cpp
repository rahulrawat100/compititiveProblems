class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<n; j++)
            {
                if(i==j)continue;
                int cost = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({cost, j});
            }
        }

        vector<bool> trav(n);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0; i<adj[0].size(); i++)
        {
            pq.push(adj[0][i]);
        }
        trav[0]=true;

        int count=1;
        int cost=0;
        while(count<n)
        {
            int c = pq.top().first;
            int j= pq.top().second;
            pq.pop();
            if(trav[j])
              continue;
            cost+=c;
                        //cout<<c<<"  "<<j<<endl;
           for(int i=0; i<adj[j].size(); i++)
          {
               pq.push(adj[j][i]);
          }
           trav[j]=true; 
           count++;   
        }
        return cost;
    }
};