class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        int n =profits.size();
        vector<pair<int, int>> D;

        for(int i=0; i<n; i++)
        {
            D.push_back({capital[i], profits[i]});
        }

        sort(D.begin(), D.end());

        int i=0;

        while(k>0)
        {
            if(i<n&&D[i].first<=w)
            {
                pq.push(D[i].second);
                i++;
            }
           else
           {
                if(pq.empty())break;
               int p=pq.top();
               pq.pop();
               w+=p;
               k--;
           } 
        }
        return w;
    }
};