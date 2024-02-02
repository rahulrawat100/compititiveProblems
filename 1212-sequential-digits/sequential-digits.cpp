class Solution {
public:
    void calc(int curr, int high, int low, int prevD, vector<int>& res)
    {
        if(curr>high)
          return;
        if(curr>=low)
           res.push_back(curr);
           if(prevD<9)
            calc(curr*10+prevD+1, high, low, prevD+1, res);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1; i<9; i++)
        {
          calc(i, high, low, i, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};