class Solution {
public:
    bool compared(vector<int>& first, vector<int>& second)
    {
        if(first[2]<second[2])
            return true;
        return false;
    }
    
    int getpar(int x, vector<int>& par)
    {
        if(par[x]==x)
            return x;
        else
            return par[x]= getpar(par[x], par);
    }
    
    void uniont(int x, int y, vector<int>& par, vector<int>& rank)
    {
        int X = getpar(x, par);
        int Y = getpar(y, par);
        
        if(X==Y)
            return ;
        if(rank[X]>rank[Y])
           par[Y]=par[X];
        else if(rank[Y]>rank[X])
            par[X]=par[Y];
        else
        {
            par[Y]=par[X];
            rank[X]++;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> D;
        int n = points.size();
        for(int i=0; i<n; i++)
        {

            for(int j=i+1; j<n; j++)
            {
                vector<int> M;
                M.push_back(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]));
                M.push_back(i);
                M.push_back(j);
                D.push_back(M);
            }

        }
        vector<int> par(n, 0);
        vector<int> rank(n, 1);
        for(int i=0; i<n; i++)
        {
            par[i]=i;
        }
        sort(D.begin(), D.end());
      
     //   vector<int> dist(n, INT_MAX);
        int cost=0;
        int count =0;
        for(int p=0; p<D.size(); p++)
        {
            int X = getpar(D[p][1], par);
            int Y = getpar(D[p][2], par);
            
            if(X!=Y)
            {
                uniont(D[p][1], D[p][2], par, rank);
                cost+= D[p][0];
                count++;
              
            }
            if(n==count)
                break;
        }
        return cost;
        
    }
};