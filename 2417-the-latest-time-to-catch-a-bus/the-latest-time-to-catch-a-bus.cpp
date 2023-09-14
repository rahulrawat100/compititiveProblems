class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int n = passengers.size();
        int m = buses.size();
        int j=0;
        for(int i=0; i<buses.size()-1; i++)
        {
            int t= capacity;
            while(t>0&&j<passengers.size()&&passengers[j]<=buses[i])
            {
                j++;
                t--;
            }
        }

        int lim;
        if(n-j<capacity)
          lim=buses[m-1];
        else
          {
            int ind = min(j+capacity-1, n-1) ; 
          lim= min(passengers[ind], buses[m-1]);
          }

        j=n-1;
        while(j>=0&&passengers[j]>=lim)
        {
            if(passengers[j]==lim)
               lim--;
             j--;  
        }  
        return lim;

    }
};