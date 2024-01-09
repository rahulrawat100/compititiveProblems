class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
          int n = points.size();
          priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
          int count=1;
          vector<bool> trav(n);
          trav[0]=true;
          int curr=0;
          int cost=0;
          while(count<n)
          {
              for(int j=0; j<n; j++)
              {
                  if(trav[j])continue;
                  int cost = abs(points[curr][0]-points[j][0])+abs(points[curr][1]-points[j][1]);
                  pq.push({cost, {curr, j}});
              }

              while(trav[pq.top().second.second])
              {
                  pq.pop();
              }
              cost+=pq.top().first;
              curr=pq.top().second.second;
              pq.pop();
              trav[curr]=true;
              count++;
          }
          return cost;
          
          
          
    }
};