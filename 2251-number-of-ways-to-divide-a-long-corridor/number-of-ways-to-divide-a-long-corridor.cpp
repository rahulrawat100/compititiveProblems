class Solution {
public:
    long long calc(string& corridor, int i)
    {
        int mod = pow(10, 9)+7;
        int n = corridor.size();
        if(i==n)
          return 1;
        else
        {
            int s=0;
            while(i<n&&s<2)
            {
                if(corridor[i]=='S')
                   s++;
                 i++;  
            }
            if(s<2)return 0;

            int p=1;
            while(i<n&&corridor[i]!='S')
            {
                i++;
                p++;
            }
            if(i==n)
              return calc(corridor, i)%mod;
            return (p*calc(corridor, i))%mod;
        }  
    }
    int numberOfWays(string corridor) {
        return calc(corridor, 0);
    }
};