class Solution {
public:

    int digit(string s)
    {
       int neg=1;;
       int i=0;
       if(s[i]=='-')
       {
          i++;
          neg=-1;
       }
        int res=0;
        for(; i<s.size(); i++)
        {
           res= res*10+(s[i]-'0');
        }
        return res*neg;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
         stack<int> D;
        for(int i=0; i<n; i++)
        {
             if(tokens[i]=="+"||tokens[i]=="*"||tokens[i]=="/"||tokens[i]=="-")
             {
                 int B= D.top();
                 D.pop();
                 int A= D.top();
                 D.pop();
                 if(tokens[i]=="+")
                    D.push(A+B);
                 if(tokens[i]=="*")
                    D.push(A*B);
                 if(tokens[i]=="/")
                    D.push(A/B);
                 if(tokens[i]=="-")
                    D.push(A-B);         
             }
             else
               D.push(digit(tokens[i]));
        }
        return D.top();
    }
};