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
          int n = points.size();
          priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
          for(int i=0; i<n; i++)
          {
              for(int j=i+1; j<n; j++)
              {
                  int cost = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                 // cout<<i<<"  "<<j<<"  "<<cost<<endl;
                  pq.push({cost, {i, j}});
              }
          }

          vector<int> par(n);

          for(int i=0; i<n; i++)
          {
              par[i]=i;
          }

          int count=1;
          int cost=0;
          while(!pq.empty()&&count<n)
          {
              int i=pq.top().second.first;
              int j=pq.top().second.second;

              int I=getpar(par, i);
              int J=getpar(par, j);

              if(I!=J)
              {
                //  cout<<i<<"  "<<j<<endl;
                     cost+=pq.top().first;
                  //   cout<<cost<<endl;
                     par[I]=J;
                     count++;
              }
                            pq.pop();
          }

          return cost;
    }
};