class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        int lim = min((int)nums1.size(), k);
        for(int i=0; i<lim;i++)
        {
            pq.push({-nums1[i]-nums2[0], {i, 0}});
        }
        vector<vector<int>> res;
        while(k>0)
        {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            k--;
            int i= p.second.first;
            int j = p.second.second;
            res.push_back({nums1[i], nums2[j]});
           if(j+1<nums2.size()) 
             pq.push({-nums1[i]-nums2[j+1], {i, j+1}});
        }
        return res;
    }
};