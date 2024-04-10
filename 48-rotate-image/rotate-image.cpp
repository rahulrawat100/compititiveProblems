class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
       for(int i=0; i<n/2; i++)
       { 
        for(int j=i; j<n-1-i; j++)
        {
           int t = matrix[i][j];
           matrix[i][j]=matrix[n-1-j][i];
           matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
           matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
           matrix[j][n-1-i] =t;
        }
       }
    }
};

// [[15,14,1,5]
// ,[13,3,4,2]
// ,[7,6,8,10]
// ,[16,12,9,11]]

// [[15,1,9,11]
// ,[14,3,8,10]
// ,[13,6,4,2]
// ,[16,7,12,5]]

// [[15,1,9,11]
// ,[14,3,8,13]
// ,[12,6,4,2]
// ,[16,7,10,5]]