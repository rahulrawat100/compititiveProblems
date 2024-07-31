class Solution {
public:
    int calc(vector<vector<int>>& books, int i, int currW, int maxH, int sW, vector<unordered_map<int, unordered_map<int, int>>>& DP)
    {
        if( i == books.size())
             return maxH;
            else
            if(DP[i].find(currW)!=DP[i].end()&&DP[i][currW].find(maxH)!=DP[i][currW].end())
               return DP[i][currW][maxH];
            {
                int res=INT_MAX;
                if(currW+books[i][0]<=sW)
                   res= min(res, calc(books, i+1, currW+books[i][0], max(maxH, books[i][1]), sW, DP));
                res =min(res, maxH +calc(books, i+1, books[i][0], books[i][1], sW, DP));   
                return DP[i][currW][maxH]=res;
            }
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<unordered_map<int, unordered_map<int, int>>> DP(n);
        return calc(books, 1, books[0][0], books[0][1], shelfWidth, DP);
    }
};