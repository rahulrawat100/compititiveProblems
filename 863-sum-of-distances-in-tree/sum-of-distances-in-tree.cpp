class Solution {
public:
    unordered_map<int, unordered_map<int, int>> downNodes;

    int calcNodes(vector<vector<int>>& adj, int i, vector<bool>& trav)
    {
        int res=1;
        trav[i]=true; 
        for(int j=0; j<adj[i].size(); j++)
        {
             if(trav[adj[i][j]])
               continue;  
             downNodes[i][adj[i][j]]=calcNodes(adj, adj[i][j], trav);  
             res+=downNodes[i][adj[i][j]];
           //  cout<<i<<"  "<<adj[i][j]<<"  "<<downNodes[i][adj[i][j]]<<endl; 
        }   
        trav[i]=false;
        return res;
    }

    int calc(vector<vector<int>>& adj, int i, vector<bool>& trav, int dis)
    {
        trav[i]=true;
        int res=dis;
        
        for(int j=0; j<adj[i].size(); j++)
        {
            if(!trav[adj[i][j]])
               res+=calc(adj, adj[i][j], trav, dis+1);
        } 
        trav[i]=false;
        return res;
    }

    void calcres(vector<vector<int>>& adj, int i, vector<int>& res, vector<bool>& trav)
    {
        int n = adj.size();
        trav[i]=true;  
        for(int j=0;j<adj[i].size();j++)
        {
            if(!trav[adj[i][j]])
            {
            res[adj[i][j]]=res[i]-(downNodes[i][adj[i][j]])+(n-downNodes[i][adj[i][j]]);
            calcres(adj, adj[i][j], res, trav);
            }
        }
        trav[i]=false;  
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {     
        vector<vector<int>> adj(n);
         if(n==1)
           return {0};
        int m =edges.size();
        vector<int> deg(n, 0);
        for(int i=0; i<m; i++)
        {
            int u = edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        int start;

        for(int i=0; i<n; i++)
        {
            if(deg[i]==1)
            {
                start=i;
                break;
            }
        }
       // cout<<start<<endl;
        vector<bool> trav(n);
        calcNodes(adj, start, trav);
       // cout<<"node"<<endl;
        vector<int> res(n);
        res[start]=calc(adj, start, trav, 0);
        //cout<<"first"<<endl;
        calcres(adj, start, res, trav);
        return res;
    }
};


/*


0 edges->nodes and distance

0 ---->1

edge I used =sum of nodes+1



*/