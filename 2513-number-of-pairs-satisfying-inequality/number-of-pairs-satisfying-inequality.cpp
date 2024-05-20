class Solution {
public:
    void Sorty(vector<pair<int, int>>& D, int i, int j, vector<int>&DP, int diff)
    {
        //cout<<i<<" "<<j<<endl;
        if(i>=j)
           return;
        else
        {
            int mid = i+(j-i)/2;
            Sorty(D, i, mid, DP, diff);
            Sorty(D, mid+1, j, DP, diff);
            merge(D,i,j, DP, diff);
        }   
    }


    void merge(vector<pair<int, int>>& D, int i, int j, vector<int>& DP, int diff)
    {
        //cout<<i<<"  "<<j<<endl;
        vector<pair<int, int>> res;
        int mid =i+(j-i)/2;
        int i1=i; 
        int j1=mid+1;
        for(;j1<=j;j1++)
        {
            for(;i1<=mid;i1++)
            {
                if(D[i1].first>D[j1].first+diff)
                   break;
            }
            //cout<<right[j].second<<"  "<<i<<endl;
            DP[D[j1].second]+=i1-i;
        }
        i1=i;
        j1=min(j,mid+1);
        while(i1<=mid||j1<=j)
        {
            //cout<<i1<<"  *  "<<mid<<"    "<<j1<<endl;
            if(i1<=mid&&j1<=j)
            {
                if(D[i1].first<=D[j1].first)
                {
                    res.push_back(D[i1]);
                      i1++;
                }
                  else
                   {
                      res.push_back(D[j1]);
                      j1++;
                   }
            }
            else if(i1<=mid)
            {
                    res.push_back(D[i1]);
                      i1++;
            }
            else
            {
                res.push_back(D[j1]);
                      j1++;
            }
        }
        //cout<<"--"<<endl;
           for(int k=0; k<res.size(); k++)
            {
                D[i+k]=res[k];
            }
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();

        vector<pair<int, int>> D;
        for(int i=0; i<n; i++)
        {
            D.push_back({nums1[i]-nums2[i], i});
        }
        vector<int>DP(n, 0);
        Sorty(D, 0, n-1, DP, diff);
        long long res=0;
       for(int i=0; i<n; i++)
        {
            //cout<<D[i].first<<"  "<<D[i].second<<"  "<<DP[i]<<endl;
            res+=DP[i];
        }
        return res;

    }
};

//1 0 4
//

//      1              0               4
//      