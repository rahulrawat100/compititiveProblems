class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n, 0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
               if(mat[i][j]==1)
                  row[i]++;
            }
        }
        vector<int> col(m, 0);
        for(int j=0; j<m; j++)
        {
            for(int i=0; i<n; i++)
            {
               if(mat[i][j]==1)
                  col[j]++;
            }
        }
         int res=0;
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==1 && row[i]==1&& col[j]==1)
                  res++;
            }
        }
        return res;
    }
};