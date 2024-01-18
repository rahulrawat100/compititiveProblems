class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
           return n;
        vector<int> D(n, 0);
        D[0]=1;
        D[1]=2;

        for(int i=2;i<n; i++)
        {
            D[i]=D[i-1]+D[i-2];
        }
        return D[n-1];



    }
};