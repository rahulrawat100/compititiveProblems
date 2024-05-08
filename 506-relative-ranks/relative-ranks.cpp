class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> D;
        int n = score.size();

        for(int i=0; i<n; i++)
        {
            D.push_back({score[i], i});
        }

        sort(D.begin(), D.end());

        vector<string> res(n);
        for(int i=0; i<n-3; i++)
        {
            string t=to_string(n-i);
            res[D[i].second]=t;
        }
        res[D[n-1].second]="Gold Medal";
        if(n>1)
        res[D[n-2].second]="Silver Medal";
        if(n>2)
        res[D[n-3].second]="Bronze Medal";
        return res;
    }
};