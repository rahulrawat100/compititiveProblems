class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost;
        
        int n = matches.size();
        
        for(int i=0; i<n; i++)
        {
            lost[matches[i][1]]++;
            if(lost.find(matches[i][0])==lost.end())
                lost[matches[i][0]]=0;
        }
        // vector<vector<int>> res(2);
        vector<int> A, B;
        for(auto it: lost)
        {
            if(it.second==0)
                A.push_back(it.first);
            if(it.second==1)
                B.push_back(it.first);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        return {A,B};
    }
};