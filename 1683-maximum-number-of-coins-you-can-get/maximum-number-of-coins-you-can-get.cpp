class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int sum=0;
        for(int i=n-2; i>=n/3; i-=2)
        {
           sum+=piles[i];
        }
        return sum;
    }
};