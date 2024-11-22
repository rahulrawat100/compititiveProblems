class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_map<string, int> mp;
        int count =0;
        for(int i=0; i<m; i++)
        {
            string orig="";
            string rev="";

            for(int j=0; j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    orig +="1";
                    rev+="0";
                }
                else
                {
                    orig +="0";
                    rev+="1"; 
                }
            }
            mp[orig]++;
            mp[rev]++;
            count=max(count, mp[orig]);
            count=max(count, mp[rev]);
        }
        return count;
    }
};