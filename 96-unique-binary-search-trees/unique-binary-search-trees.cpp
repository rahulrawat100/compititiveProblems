class Solution {
public:
    int calc(int i, int j)
    {
        if(i>=j)
           return 1;
        else
          {
              int res=0;
              for(int k=i; k<=j; k++)
              {
                 res+=calc(i, k-1)*calc(k+1, j);
              }
              return res;
          }   
    }
    int numTrees(int n) {
        return calc(1, n);
    }
};