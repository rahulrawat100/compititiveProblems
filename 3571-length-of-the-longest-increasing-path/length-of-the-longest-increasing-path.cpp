bool compare(vector<int>& A, vector<int>& B)
    {
        if(A[0]<B[0])
           return true;
        if(A[0]>B[0])
           return false;   
        return A[1]>B[1];     
    }

class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int a= coordinates[k][0];
        int b = coordinates[k][1];
        int n =coordinates.size();
        sort(coordinates.begin(), coordinates.end(), compare);
        
        for(int i=0; i<coordinates.size(); i++)
        {
            if(coordinates[i][0]==a&&coordinates[i][1]==b)
            {
                k=i;
                break;
            }
        }
        
        int res=0;
        vector<int> DP1,DP2;
            int i=0;
          while(i<k&&(coordinates[i][1]>=b||coordinates[i][0]>=a))
          {
              i++;
          }
            if(i<k)
              DP1.push_back(coordinates[i][1]);
          for(; i<k; i++)
          {
            if(coordinates[i][1]>=b)
                continue;
              if(DP1.back()<coordinates[i][1])
                  DP1.push_back(coordinates[i][1]);
              else
              {
                  auto it = lower_bound(DP1.begin(), DP1.end(), coordinates[i][1]);
                  DP1[it-DP1.begin()]=coordinates[i][1];
              }
            
          }
            
            
        
      //  cout<<k<<endl;
         i=k;
        while(i<n&&(coordinates[i][0]==a||coordinates[i][1]<=b))
        {
            i++;
        //    cout<<i<<endl;
        }
        if(i<n) 
           DP2.push_back(coordinates[i][1]);
        //cout<<k<<endl;
        for(; i<n; i++)
        {
            if(coordinates[i][1]<=b)
                continue;
              if(DP2.back()<coordinates[i][1])
                  DP2.push_back(coordinates[i][1]);
              else
              {
                  auto it = lower_bound(DP2.begin(), DP2.end(), coordinates[i][1]);
                  DP2[it-DP2.begin()]=coordinates[i][1];
              }
            
          }
       // cout<<DP1.size()<<"  "<<DP2.size()<<endl;
        return DP1.size()+DP2.size()+1;
        
        
    }
};