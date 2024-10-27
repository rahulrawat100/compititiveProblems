class Solution {
public:
    long long GCD(long long a, long long b)
    {
        if(a>b)
           return GCD(b, a);
        else if(b%a==0)
           return a;
        else
           return GCD(b%a, a);      
    }

    long long LCM(long long a, long long b)
    {
        long long gcd = GCD(a, b);
        return (a*b)/gcd;
    }
    long long maxScore(vector<int>& nums) {
        int n =nums.size();
        if(n==1)
           return nums[0]*nums[0];
        long long res=0;
        for(int i=0; i<n; i++)
        {
            long long gcd=i==0?nums[1]:nums[0];
            long long lcm=gcd;
            for(int j=i==0?2:1; j<n; j++)
            {
                if(i==j)continue;
                gcd = GCD(gcd, nums[j]);
                lcm = LCM(lcm, nums[j]);
            }
            res=max(res, gcd*lcm);
        }
           long long gcd=nums[0];
           long long lcm = gcd;
            for(int j=1; j<n; j++)
            {
                gcd = GCD(gcd, nums[j]);
                lcm = LCM(lcm, nums[j]);
            }
            res=max(res, gcd*lcm);
        return res;
    }
};