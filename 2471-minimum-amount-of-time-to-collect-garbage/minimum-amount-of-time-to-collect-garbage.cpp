class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g=-1;
        int p=-1;
        int m=-1;
        int gc=0;
        int pc=0;
        int mc=0;

        for(int i=0; i<garbage.size(); i++)
        {
            for(int j=0; j<garbage[i].size(); j++)
            {
                if(garbage[i][j]=='G')
                {
                  g=i;
                  gc++;
                }
                else if(garbage[i][j]=='M')
                {
                  m=i;
                  mc++;
                }
                else if(garbage[i][j]=='P')
                {
                  p=i;
                  pc++;
                }
            }
        }
       // cout<<g<<"  "<<m<<"   "<<p;
        vector<int> cum(travel.size());
        cum[0]=travel[0];
        for(int i=1; i<travel.size(); i++)
        {
            cum[i]=travel[i]+cum[i-1];
        }
        long long res=0;
        if(g>0)
          res+=cum[g-1];
        if(p>0)
          res+=cum[p-1];
        if(m>0)
          res+=cum[m-1];    
        return gc+mc+pc+res;
    }
};