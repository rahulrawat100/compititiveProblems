class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        stack<char> st;
        int c=k;
        for(int i=0; i<n; i++)
        {
            if(st.size()<=k&&num[i]=='0')
            {
                while(!st.empty())
                {
                    st.pop();
                    k--;
                }
                continue;
            }
            else if(!st.empty())
            {
                while(k>0&&!st.empty()&&st.top()>num[i])
                {
                    st.pop();
                    k--;
                }
            }
               if(st.size()==(n-c))
               {
                k--;
                continue;
               }
               st.push(num[i]);

        }
        string res="";
                 while(k>0&&!st.empty())
                {
                    st.pop();
                    k--;
                }
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        if(res.size()==0)return "0";
        return res;

    }
};