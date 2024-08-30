class Solution {
public:
    int DP[101][101][101];
    int calc(vector<pair<int, int>>& group, int i, int j, int extra)
    {
        //cout<<i<<"  "<<j<<"  "<<extra<<endl;
        if(i>j)
           return 0;
         if(i==j)
           return (group[i].second+extra) * (group[i].second+extra);
         if(DP[i][j][extra]!=-1)
           return DP[i][j][extra];  
         else
         {
            int res=(group[i].second+extra) * (group[i].second+extra)+calc(group, i+1, j, 0);
            for(int k=i+1; k<=j; k++)
            {
                if(group[i].first==group[k].first)
                {
                    res=max(res, calc(group, i+1, k-1, 0)+calc(group, k, j, group[i].second+extra));
                }
            }
            return DP[i][j][extra]=res;
         }    
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(DP, -1, sizeof(DP));
        vector<pair<int, int>> group;
        group.push_back({boxes[0], 0});
        int curr=boxes[0];
        int ind=0;
        for(int i=0; i<n; i++)
        {
            if(boxes[i]==curr)
               {
                  group[ind].second++;
               }
              else
              {
                  curr=boxes[i];
                  group.push_back({boxes[i], 1});
                  ind++;
              } 
        }

        return calc(group, 0, group.size()-1, 0);
    }
};