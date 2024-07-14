class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<bool> vtrav(n-1);
        vector<bool> htrav(m-1);
        
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        long long i=0;
        long long j=0;
        long long cost=0;
        while(i<m-1||j<n-1)
        {
            if(i<m-1&&j<n-1)
            {
                if(horizontalCut[i]>verticalCut[j])
                {

                   cost+= (j+1)*horizontalCut[i];
                   //cout<<"h  "<<horizontalCut[i]<<endl;
                    //remh-=horizontalCut[i];
                    i++;
                }
                else
                {
                    cost+= (i+1)*verticalCut[j];
                 //   remv-=verticalCut[j];
                   // cout<<"v  "<<verticalCut[j]<<endl;
                    j++;
                }
            }   
            else if(i<m-1)
            {
                   cost+= (j+1)*horizontalCut[i];
                    // remh-=horizontalCut[i];
                    // cout<<"h  "<<horizontalCut[i]<<endl;
                    i++;
            }
            else
            {
                    cost+= (i+1)*verticalCut[j];
                    // remv-=verticalCut[j];
                    // cout<<"v  "<<verticalCut[j]<<endl;
                    j++;
            }
            
        }
        return cost;
    }
};