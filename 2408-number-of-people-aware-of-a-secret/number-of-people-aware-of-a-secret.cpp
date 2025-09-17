class Solution {
public:
    int mod = pow(10, 9)+7;
    int calc(int day, int delay, int forget, int n, vector<int>& D)
    {
        if(day>n)
           return 0;
        if(D[day]!=-1)
          return D[day];
        else
        {
            int res= n-day>=forget?0:1;

            for(int j=delay; j<forget; j++)
            {
                res+=calc(day+j, delay, forget, n, D);
                res%=mod;
            }
            return D[day]=res;
        }   
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> D(n+1, -1);
        return calc(1, delay, forget, n, D);
    }
};


// 1 -- (forget -delay)
//  