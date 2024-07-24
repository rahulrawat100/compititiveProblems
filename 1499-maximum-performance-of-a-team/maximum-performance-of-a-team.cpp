class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> D;

        for(int i=0; i<n; i++)
        {
            D.push_back({efficiency[i], speed[i]});
        }

        sort(D.begin(), D.end());
        long long spd=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int curr=D[n-k].first;
                long long perf = 0;
        for(int i=n-1;i>=n-k; i--)
        {
           spd+= D[i].second;
           perf = max(perf, spd*D[i].first);
           pq.push(D[i].second);
        }
        perf = max(perf, spd*curr);
        for(int i=n-1-k;i>=0; i--)
        {
            //cout<<i<<"  "<<perf<<endl;
            if(pq.top()<D[i].second)
            {
                int x = pq.top();
                spd+=D[i].second;
                spd-=x;
                pq.pop();
                pq.push(D[i].second);
                curr=D[i].first;
                perf = max(perf, curr*spd);
            }
        }
        return perf%1000000007;


    }
};