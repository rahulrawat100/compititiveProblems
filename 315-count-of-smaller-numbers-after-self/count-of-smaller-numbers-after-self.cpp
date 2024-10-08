class Solution {
public:
    
    void sort(vector<pair<int, int>>& numpos, int i, int j, vector<int>& res)
    {
        int n = numpos.size();
        if(i==j)
          return;
        else
        {
            int mid = i+(j-i)/2;
            sort(numpos, mid+1, j, res);
            sort(numpos, i, mid, res);
            merge(numpos, i, j, res);
        }  
    }

    void merge(vector<pair<int, int>>& numpos, int i, int j, vector<int>& res)
    {
        int mid = i+(j-i)/2;
        vector<pair<int,int>> t;
        int l=mid+1;
        for(int k=i;k<=mid; k++)
        {
           for(;l<=j;l++)
           {
              if(numpos[l].first>=numpos[k].first)
                break;
           }
           res[numpos[k].second]+=l-mid-1;
        }
       l=mid+1;
       int s=i;
       //cout<<i<<"  "<<j<<"  "<<l<<"  "<<mid<<endl;
       while(i<=mid||l<=j)
       {
          if(i>mid)
          {
             t.push_back(numpos[l]);
             l++;
          }
          else if(l>j)
          {
            t.push_back(numpos[i]);
            i++;
          }
          else if(numpos[i].first<numpos[l].first)
          {
            t.push_back(numpos[i]);
            i++;
          }
          else
          {
             t.push_back(numpos[l]);
             l++;
          }
       }

       for(int k=0; k<t.size(); k++)
       {
        //    cout<<t[k].first<<endl;
           numpos[s+k]=t[k];
       }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> numpos;
        for(int i=0; i<n; i++)
        {
            numpos.push_back({nums[i], i});
        }
        vector<int> res(n, 0);
        sort(numpos, 0, n-1, res);
        return res;
    }
};