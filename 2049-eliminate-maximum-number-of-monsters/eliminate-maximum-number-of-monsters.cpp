class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> reach;

        int n = dist.size();

        for(int i=0; i<n; i++)
        {
            reach.push_back((dist[i]+speed[i]-1)/speed[i]);
        }

        sort(reach.begin(), reach.end());
        //cout<<reach[0]<<endl;
        for(int i=1; i<n; i++)
        {
            //cout<<reach[i]<<endl;
            if(reach[i]<=i)
               return i;
        }
        return n;
    }
};