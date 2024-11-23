class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<long long, int>> pq;
        int res=n+1;
        long long cum=0;
        pq.push({0, -1});
        for(int i=0; i<n; i++)
        {
            cum+=nums[i];
            pq.push({-cum, i});

            while(!pq.empty() && cum+pq.top().first>=k)
            {
                res=min(res, i-pq.top().second);
                pq.pop();
            }
        }
        return res==n+1?-1:res;
    }
};