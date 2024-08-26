class Solution {
public:
    int calc(unordered_map<int, int>& nums, int x)
    {
        vector<int> D;
        int i=0;
        int copy=x;
        while(x>0)
        {
            D.push_back(x%10);
            x=x/10;
            i++;
        }
        vector<bool> trav(7);
        vector<int> DP;
        int res=0;
        int lim =D.size();
        unordered_set<int> s;
        res+=nums[copy];
        s.insert(copy);
        for(int i=0; i<lim; i++)
        {
            for(int j=i+1;j<lim;j++)
            {
               int t= copy + (D[j]-D[i])*pow(10, i)+(D[i]-D[j])*pow(10, j);
               //cout<<copy<<"  "<<t<<endl;
              if(s.find(t)==s.end())
              { 
               res+=nums[t];
               s.insert(t);
              }

               int temp = D[i];
               D[i]=D[j];
               D[j]=temp;
              for(int l=0; l<lim;l++)
              {
                for(int r=l+1;r<lim;r++)
                {
                    int t2= t + (D[r]-D[l])*pow(10, l)+(D[l]-D[r])*pow(10, r);
                                  if(s.find(t2)==s.end())
                                { 
                                res+=nums[t2];
                                    s.insert(t2);
                                }
                   // cout<<copy<<"  "<<t2<<endl;
                }
              }
              temp = D[i];
               D[i]=D[j];
               D[j]=temp;

            }
        }
        return res;
    }


    int countPairs(vector<int>& nums) {
        unordered_map<int, int> p;
        int res=0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
                   p[nums[0]]++;
        for(int i=1; i<n; i++)
        {
           res+=calc(p, nums[i]);
           p[nums[i]]++;
           //cout<<"..."<<endl;
           //cout<<i<<"  "<<res<<endl;
        }
        return res;
    }
};