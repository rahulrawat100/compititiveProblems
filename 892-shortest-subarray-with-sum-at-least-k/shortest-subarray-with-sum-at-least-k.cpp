class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        int l=0;
        while(l<n&&nums[l]<0)
        {
            l++;
        }
        for(int i=l; i<n; i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }

        vector<int> nse(n+1, n+1);
        stack<int> D;
        for(int i=0; i<=n; i++)
        {
            while(!D.empty() && prefix[D.top()]>prefix[i])
            {
                nse[D.top()]=i;
                D.pop();
            }
            D.push(i);
        }
        // for(int i=0; i<=n; i++)
        // {
        //     cout<<prefix[i]<<"   ";
        // }
        // cout<<endl;
        // for(int i=0; i<=n; i++)
        // {
        //     cout<<nse[i]<<"   ";
        // }
        //  cout<<"1"<<endl;
        int i=l;
        int j=l;
        int res=n+1;
        while(i<n&&nums[i]<=0)
        {
            i++;
            j++;
        }
        // cout<<"2"<<endl;
        while(j<n)
        {
            cout<<j<<endl;
            while(j<n&&prefix[j]-prefix[i]<k)
            {
                j++;
                if(nse[i]==j)
                   break;
            }
            if(nse[i]==j)
            {
                i=j;
                continue;
            }
            while(i<j&&(prefix[j]-prefix[i]>=k || nums[i]<=0))
            {
                if(prefix[j]-prefix[i]>=k)
                   res=min(res, j-i);
                i++;
            }

            while(nse[i]<j)
            {
                i=nse[i];
                if(prefix[j]-prefix[i]>=k)
                   res=min(res, j-i);
            }
        }
        return res==n+1?-1:res;
        
    }
};