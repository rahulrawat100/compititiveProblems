class Solution {
public:
    int numSteps(string s) {
      int n =s.size();
      int carry=0;
      int i=n-1;
      int ans=0;
      int l=0;
      while(s[l]=='0')
      {
        l++;
      }
      while(i>l)
      {
          if(s[i]=='1')
          {
             if(carry==1)
             {
                ans++;
                i--;
             }
             else
             {
                carry=1;
                ans+=2;
                i--;
             }
          }
          else
          {
            if(carry==1)
            {
                ans+=2;
                i--;
            }
            else
            {
             ans++;
             i--;
            }
          }
      }

      if(carry==1)
        return ans+1;
      return ans;  
         

    }
};