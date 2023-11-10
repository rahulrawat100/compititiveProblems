class Solution {
public:
    void calc(unordered_map<int, vector<int>>& ad, vector<int>& res, int curr, set<int>& trav)
    {
        if(trav.find(curr)!=trav.end())
           return;
        else
        {
            trav.insert(curr);
            res.push_back(curr);
            for(int i=0; i<ad[curr].size(); i++)
            {
                  calc(ad, res, ad[curr][i], trav);
            }
        }   
    }
    vector<int> restoreArray(vector<vector<int>>& adj) {
        unordered_map<int, int> D;
        int n =adj.size();
        unordered_map<int, vector<int>> ad;
        for(int i=0; i<n; i++)
        {
            ad[adj[i][0]].push_back(adj[i][1]);
            ad[adj[i][1]].push_back(adj[i][0]);
            D[adj[i][0]]++;
            D[adj[i][1]]++;
        }
        int start=0;
        for(auto it: D)
        {
            if(it.second==1)
            {
                start=it.first;
                break;
            }
        }
        vector<int> res;
        set<int> trav;
        calc(ad,res, start, trav);
        return res;
    }
};