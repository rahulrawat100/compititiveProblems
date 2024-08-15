class Solution {
public:
    void calc(vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res, int i, bool prev)
    {
        cout<<target<<endl;
        if(target==0)
        {
            res.push_back(curr);
            return;
        }
        if(i==candidates.size() || target<0 || candidates[i]>target)
           return;
        else
        {
             calc(candidates, target, curr, res, i+1, false);
             if(prev ||candidates[i]!=candidates[i-1])
             {
             curr.push_back(candidates[i]);
             calc(candidates, target-candidates[i], curr, res, i+1, true);
             curr.pop_back();
             }
        }   
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        calc(candidates, target, curr, res, 0, true);
        return res;
    }
};