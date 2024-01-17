class Solution {
public:
    int calc(vector<vector<pair<int, int>>> adj, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq, int count, vector<bool>& trav, int t)
    {
        if(count == adj.size())
           return t;
        if(pq.size()==0)
          return -1;
        else
        {
            int time = pq.top().first;
            vector<int> temp;
            while(count<adj.size()&&!pq.empty()&&pq.top().first==time)
            {
                int v = pq.top().second;
                cout<<v<<endl;
                pq.pop();
                if(trav[v])continue;
                trav[v]=true;
                count++;
                temp.push_back(v);
            }
            t=time;
            for(auto v:temp)
            {
                for(int j=0; j<adj[v].size(); j++)
                {
                    if(trav[adj[v][j].first])continue;
                    cout<<"pq  "<<adj[v][j].first<<endl;
                    pq.push({t+adj[v][j].second, adj[v][j].first});
                }
            }
            return calc(adj, pq, count, trav, t);
        }  
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<pair<int, int>>> adj(n);

         int m = times.size();

         for(int i=0;i<m; i++)
         {
             int u= times[i][0];
             int v= times[i][1];
             int w= times[i][2];

             adj[u-1].push_back({v-1, w});
         }

         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
         vector<bool> trav(n);
         pq.push({0, k-1});
         return calc(adj, pq, 0, trav, 0);
    }
};