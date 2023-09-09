class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        
        long long ans=LLONG_MAX;
        int mod = pow(10, 9)+7;
        sort(packages.begin(), packages.end());
        int n = packages.size();
        vector<long long> prefix(n+1,0);

        for(int i=0; i<n; i++)
        {
            prefix[i+1]=prefix[i]+packages[i];
        }
        for(int i=0; i<boxes.size(); i++)
        {
            sort(boxes[i].begin(), boxes[i].end());
            int m = boxes[i].size();
            if(boxes[i][m-1]<packages[n-1])
              continue;
            int j=0;
            long long curr=0;
            int prevInd=0;
            for(int k=0; k<m; k++)
            {
                if(boxes[i][k]>=packages[n-1])
                {
                   curr+=(long long)(n-prevInd)*boxes[i][k]-(prefix[n]-prefix[prevInd]);
                   //curr%=mod;   
                   break;
                }
                auto it = upper_bound(packages.begin(), packages.end(), boxes[i][k]);
                //cout<<*it<<endl;
                   it--;
                int ind = it-packages.begin(); 
                //cout<<ind<<endl;
                curr+=(long long)(ind-prevInd+1)*boxes[i][k]-(prefix[ind+1]-prefix[prevInd]);
                //curr%=mod;  
                prevInd = ind+1;
            }
            //cout<<i<<"  "<<curr<<endl;
            ans=min(ans, curr);

        }
            
          return ans==LLONG_MAX?-1:ans%mod;
    }
};