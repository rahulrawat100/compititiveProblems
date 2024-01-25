class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());
        int n = tasks.size();
        int m =processorTime.size();
        int res=0;

        for(int i=n-1; i>=0; i--)
        {
            int p = m-(i+4)/4;
            res=max(res, tasks[i]+processorTime[p]);
        }
        return res;
    }
};