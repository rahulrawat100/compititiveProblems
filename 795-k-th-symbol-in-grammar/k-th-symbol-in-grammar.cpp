class Solution {
public:
    int calc(int n, int k, bool rev)
    {
        if(n==2)
        {
            int ans =k-1;
            if(rev)
            return abs(ans-1);
           else
            return  ans;
        }
        if(k<=pow(2, n-2))
          return calc(n-1, k, rev);
        else
        {
            if(n%2==0)rev=!rev;
          return calc(n-1, pow(2, n-1)-k+1, rev)  ;
        }
    }
    int kthGrammar(int n, int k) {
        if(n==1 || k==0)
          return 0;
        return calc(n, k, false);
    }
};



