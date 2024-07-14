class Solution {
public:
    int calc(vector<int>& horizontalCut, vector<int>& verticalCut, int i, int j, int m, int n, vector<bool>& htrav, vector<bool>& vtrav)
    {
        if(i==m-1&&j==n-1)
            return 0;
        else
        {
            int cost=INT_MAX;
            for(int x=0; x<m-1;x++)
            {
                if(!htrav[x])
                {
                    htrav[x]=true;
                    cost=min(cost, horizontalCut[x]*(j+1)+calc(horizontalCut, verticalCut, i+1, j, m, n, htrav, vtrav));
                    htrav[x]=false;
                }
            }
           for(int x=0; x<n-1;x++)
            {
                if(!vtrav[x])
                {
                    vtrav[x]=true;
                    cost=min(cost, verticalCut[x]*(i+1)+calc(horizontalCut, verticalCut, i, j+1, m, n, htrav, vtrav));
                    vtrav[x]=false;
                }
            }
            return cost;
        }
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<bool> vtrav(n-1);
        vector<bool> htrav(m-1);
        
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        int remh=0;
        for(int i=0; i<m-1; i++)
        {
            remh+=horizontalCut[i];
        }
        int remv=0;
        for(int i=0; i<n-1; i++)
        {
            remv+=verticalCut[i];
        }
        int i=0;
        int j=0;
        int cost=0;
        while(i<m-1||j<n-1)
        {
            if(i<m-1&&j<n-1)
            {
                if(horizontalCut[i]>verticalCut[j])
                {

                   cost+= (j+1)*horizontalCut[i];
                   cout<<"h  "<<horizontalCut[i]<<endl;
                    remh-=horizontalCut[i];
                    i++;
                }
                else
                {
                    cost+= (i+1)*verticalCut[j];
                    remv-=verticalCut[j];
                    cout<<"v  "<<verticalCut[j]<<endl;
                    j++;
                }
            }   
            else if(i<m-1)
            {
                   cost+= (j+1)*horizontalCut[i];
                    remh-=horizontalCut[i];
                    cout<<"h  "<<horizontalCut[i]<<endl;
                    i++;
            }
            else
            {
                    cost+= (i+1)*verticalCut[j];
                    remv-=verticalCut[j];
                    cout<<"v  "<<verticalCut[j]<<endl;
                    j++;
            }
            
        }
        return cost;
       // return calc(horizontalCut, verticalCut, 0, 0, m, n, htrav, vtrav);
    }
};