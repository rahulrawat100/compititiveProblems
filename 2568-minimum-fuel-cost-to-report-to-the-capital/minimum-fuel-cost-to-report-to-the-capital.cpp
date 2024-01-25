class Solution {
public:
    int calc(vector<vector<int>>& adj,  int i, int seats, vector<bool>& trav, long long& res)
     {
         if(trav[i])return 0;
         trav[i]=true;
         if(adj[i].size()==1&&trav[adj[i][0]])
           {
                res+=1;
                return 1;
           }
          else
          {
              int person=1;
              for(int j=0; j<adj[i].size(); j++)
              {
                  person+=calc(adj, adj[i][j], seats,trav, res);
              }
              if(i==0)
              return person;
              res+=(long long)ceil((double)person/seats);
              return person;
          } 
     }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<vector<int>> adj(n+1);
           if(n==0)return 0;
        int m = roads.size();

        for(int i=0; i<m; i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       long long res=0;
       vector<bool> trav(n);
       int x = calc(adj, 0, seats, trav, res);
       return res;
    }
};