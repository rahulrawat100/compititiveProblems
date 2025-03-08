class Solution {
public:
    bool IsPrime(int x)
    {if(x==1)return false;
        for(int i=2; i*i<=x;i++)
        {
            if(x%i==0)
               return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int a=-1;
        int b=-1;
        int last=-1;
        for(int i=left; i<=right; i++)
        {
            if(IsPrime(i))
            {
                if(a==-1)
                   a=i;
                else if(b==-1)
                   b=i;
                else
                {
                    if(i-last<b-a)
                    {
                        a=last;
                        b=i;
                    }
                }      
                last=i;
            }
        }
        if(b==-1)a=-1;
        return {a, b};
    }
};