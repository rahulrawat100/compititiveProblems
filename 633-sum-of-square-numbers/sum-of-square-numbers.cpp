class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<long long, int> D;

        for(long long i=0; i*i<=c;i++)
        {
            if(D.find(c-i*i)!=D.end() || 2*i*i==c)
               return true;
            D[i*i]=1;   
        }
        return false;
    }
};