class Solution {
public:
    int unpaint(vector<vector<int>>& targetGrid, int x1, int x2, int y1, int y2, int val)
    {
        int count=0;
        for(int i =x1; i<=x2; i++)
        {
            for(int j=y1; j<=y2; j++)
            {
                if(targetGrid[i][j]!=val && targetGrid[i][j]!=0)
                  return 0;
            }
        }
        for(int i =x1; i<=x2; i++)
        {
            for(int j=y1; j<=y2; j++)
            {
                if(targetGrid[i][j]==val)
                  {
                      targetGrid[i][j]=0;
                      count++;
                  }
            }
        }
        return count;
    }
    int calc(vector<vector<int>>& targetGrid, unordered_map<int, int>& L1, unordered_map<int, int>& L2, unordered_map<int, int> B1, unordered_map<int, int> B2)
    {
        int m = targetGrid.size();
        int n = targetGrid[0].size();
         int res=0;
        for(auto it: L1)
        {
            int col = it.first;
           res+=unpaint(targetGrid, L1[col], L2[col], B1[col], B2[col], col);
        }
        if(res==0)return false;
        return res+calc(targetGrid, L1, L2, B1, B2);
    }
    bool isPrintable(vector<vector<int>>& targetGrid) {
        unordered_map<int, int> L1;
        unordered_map<int, int> L2;
        unordered_map<int, int> B1;
        unordered_map<int, int> B2;
        int m = targetGrid.size();
        int n = targetGrid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int val = targetGrid[i][j];
                if(L1.find(val)==L1.end())
                  L1[val]=i;
               else   
                  L1[val]= min(L1[val], i);
                L2[val]= max(L2[val], i);
                if(B1.find(val)==L1.end())
                  B1[val]=j;
               else   
                B1[val]= min(B1[val], j);
                B2[val]= max(B2[val], j);
            }
        }  
      

        return calc(targetGrid, L1, L2, B1, B2) == m*n; 
    }
};