class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse(n, n);
        vector<int> pse(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            while(!st.empty()&&heights[st.top()]>heights[i])
            {
                nse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty())
        {
            st.pop();
        }

         for(int i=n-1; i>=0; i--)
        {
            while(!st.empty()&&heights[st.top()]>heights[i])
            {
                pse[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        // for(int i=0; i<n; i++)
        // {
        //     cout<<nse[i]<<"  ";
        // }
        // cout<<endl;
        // for(int i=0; i<n; i++)
        // {
        //     cout<<pse[i]<<"  ";
        // }
        // cout<<endl;

        int i=0;
        int j=n-1;
        int res=0;
         for(int i=0; i<n; i++)
         {
            res=max(res, (nse[i]-pse[i]-1)*heights[i]);
         }
        return res;
    }
};