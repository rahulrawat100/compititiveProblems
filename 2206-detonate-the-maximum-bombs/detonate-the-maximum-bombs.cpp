class Solution {
public:

    int calc(vector<vector<int>>& adj, int i, vector<bool>& trav )
    {
        if(adj[i].size()==0)
            return 0;
        else
        {
            trav[i]= true;
            int X=0;
            for(int j=0; j<adj[i].size(); j++)
            {
                if(trav[adj[i][j]])
                    continue;
                trav[adj[i][j]]=true;
                X+= 1+calc(adj, adj[i][j], trav);
            }
            return X;
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                long long dis = pow(bombs[i][0]-bombs[j][0], 2) + pow(bombs[i][1]-bombs[j][1], 2);
                long long cdis = bombs[i][2]+bombs[j][2];
                long rad1 = 1;
                rad1*=bombs[i][2];
                rad1*=bombs[i][2];
                long rad2 = 1;
                rad2*=bombs[j][2];
                rad2*=bombs[j][2];
                if(dis<=rad1) 
                {
                    adj[i].push_back(j);
                }
                if(dis<=rad2)
                {
                    adj[j].push_back(i);
                }
                
            }
        }
        
        
     int res=0;

        for(int i=0; i<n; i++)
        {
           vector<bool> trav(n);   
          res = max(res,1+ calc(adj, i, trav));
        }
        return res;
        
    }
};

