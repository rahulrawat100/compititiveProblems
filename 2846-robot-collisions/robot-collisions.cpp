class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> data;
        int n = positions.size();

        for(int i=0; i<n; i++)
        {
            int d = directions[i]=='L'?-1:1;
            data.push_back({positions[i], healths[i], d, i});
        }
        sort(data.begin(), data.end());
        stack<vector<int>> st;

        for(int i=0; i<n; i++)
        {
            if(st.empty() || data[i][2]==1 || st.top()[2]==-1)
                st.push(data[i]);
            else
            {
                while(!st.empty())
                {
                    if(st.top()[2]==-1)
                    {
                        break;
                    }
                    else if(data[i][1]<st.top()[1])
                    {
                        st.top()[1]--;
                        data[i][1]=0;
                        if(st.top()[1]==0)
                          st.pop();
                           break;
                    }
                    else if(data[i][1]>st.top()[1])
                    {
                        st.pop();
                        data[i][1]--;
                        if(data[i][1]==0)
                          break;
                    }
                    else
                    {
                        st.pop();
                        data[i][1]=0;
                        break;
                    }
                }
                if(data[i][1]!=0)
                  st.push(data[i]);

            }
        }

        vector<vector<int>> res(st.size());

        for(int i=res.size()-1;i>=0; i--)
        {
            res[i]=st.top();
            res[i][0]=res[i][3];
            st.pop();
        }
        sort(res.begin(), res.end());

        vector<int> ans;

        for(int i=0; i<res.size(); i++)
        {
            ans.push_back(res[i][1]);
        }
        return ans;
    }
};