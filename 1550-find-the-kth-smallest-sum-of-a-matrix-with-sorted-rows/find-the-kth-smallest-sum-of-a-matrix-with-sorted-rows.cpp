class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        while(true)
        {
            m = mat.size();
            n = mat[0].size();
            vector<vector<int>> D;
            cout<<m<<"  "<<n<<endl;
            for(int i=0; i<m; i+=2)
            {
                vector<int> E;
                priority_queue<pair<int, pair<int, int>>> pq;
               if(i==m-1)
               {
                  D.push_back(mat[i]);
                  break;
               }
                for(int j=0; j<min((int)mat[i].size(), k);j++)
                { 
                    pq.push({-mat[i][j]-mat[i+1][0], {j, 0}});
                }


                while(E.size()<k&&!pq.empty())
                {
                    pair<int, pair<int, int>> p = pq.top();
                    pq.pop();
                    int y = p.second.second;
                    int x = p.second.first;
                    E.push_back(-p.first);
                   // cout<<x<<"  "<<y+1<<endl;
                   if(y+1<mat[i+1].size())
                      pq.push({-mat[i][x]-mat[i+1][y+1], {x, y+1}});
                }

                D.push_back(E);
            }
            if(D.size()==1)
              return D[0][k-1];
            mat=D;              
        }
        return 0;
    }
};