class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double time=0;
        int curr=0;
        for(int i=0; i<n; i++)
        {
           curr=max(curr, customers[i][0]);
           curr+=customers[i][1];
           time+= curr-customers[i][0];  
        }
        return time/n; 
    }
};