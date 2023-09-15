class Solution {
public:
    int getval(string s)
    {
        int val=0;
        for(int i=0; i<3;i++)
        {
            int dig = s[i]-'A';
            val+=dig*pow(26, 2-i);
        }
        return val;
    }

    bool calc(unordered_map<int, vector<int>>& To, int i, vector<int>& curr, unordered_map<int, vector<int>>& ind, int tot)
    {
         cout<<i<<endl;
        curr.push_back(i);
        if(curr.size()==tot)
          return true; 
        // if(ind.find(i)==ind.end())
        // {
        //     vector<bool> temp(To[i].size());
        //     ind[i]=temp;
        // }
        for(int j=0; j<To[i].size(); j++)
        {
            if(ind[i][j])continue;
            ind[i][j]=true;
            if(calc(To, To[i][j], curr, ind, tot))
            {
                return true;
            }
            ind[i][j]=false;
        }
        curr.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
          unordered_map<int, string> mapper;
           unordered_map<int, vector<int>> To2;
          unordered_map<int, vector<int>> To;
          unordered_map<int, vector<int>> ind;
          int n = tickets.size();
          int start=getval("JFK");
          for(int i=0; i<n; i++)
          {
              int val1 = getval(tickets[i][0]);
              mapper[val1]=tickets[i][0];
              int val2 = getval(tickets[i][1]);
              mapper[val2]=tickets[i][1];
              To[val1].push_back(val2);
          }

          for(auto it: To)
          {
              sort(it.second.begin(), it.second.end());
              cout<<mapper[it.first]<<": "<<it.first<<" : ";
              for(int i=0; i<it.second.size(); i++)
              {
                  To2[it.first].push_back(it.second[i]);
                  ind[it.first].push_back(false);
                  cout<<mapper[it.second[i]]<<"  ";
              }
              cout<<endl;
          }

        // for(auto it: To2)
        //   {
        //       cout<<mapper[it.first]<<": "<<it.first<<" : ";
        //       for(int i=0; i<it.second.size(); i++)
        //       {
        //           cout<<mapper[it.second[i]]<<"  ";
        //       }
        //       cout<<endl;
        //   }
          vector<int> curr;
          bool k=calc(To2, start, curr, ind, tickets.size()+1);
          vector<string> ans;

          for(int i=0; i<curr.size(); i++)
          {
              ans.push_back(mapper[curr[i]]);
          }
          return ans;
    }
};