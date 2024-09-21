class Solution {
public:
    int DP[101][101][101];
    int calc(vector<int>& houses, int i, int j, int k)
    {
        if(j-i==k-1)
           return 0;
        if(DP[i][j][k]!=-1)
           return DP[i][j][k];
        if(k==1)
        {
            int sum=0;
            int mid = i+(j-i)/2;
            for(int l=i; l<=j;l++)
            {
                sum+=abs(houses[l]-houses[mid]);
            }
            return DP[i][j][k]=sum;

        }   
        else
        {
            int res=INT_MAX;
            for(int l=i;l<=j-k+1;l++)
            {
                res= min(res, calc(houses, i, l, 1)+calc(houses, l+1, j, k-1));
            }
            return DP[i][j][k]=res;
        }   
    }
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        memset(DP, -1, sizeof(DP));
        return calc(houses, 0, houses.size()-1, k);
    }
};