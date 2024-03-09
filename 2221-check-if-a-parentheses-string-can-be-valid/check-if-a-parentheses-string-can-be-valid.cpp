class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n= s.size();

        int op=0;
        int cl=0;
        int any=0;
         if(n%2==1)return false;
        for(int i=0; i<n;i++)
        {
            if(op-cl+any<0)
               return false;
            if(locked[i]=='1'&&s[i]==')')
               cl++;
            else if(locked[i]=='1'&&s[i]=='(')
               op++;   
            else
              any++;      
        }

        if(abs(op-cl)>any)return false;
        op=0;
        cl=0;
        any=0;
         for(int i=n-1; i>=0;i--)
        {
            if(cl-op+any<0)
               return false;
            if(locked[i]=='1'&&s[i]==')')
               cl++;
            else if(locked[i]=='1'&&s[i]=='(')
               op++;   
            else
              any++;      
        }

        //if(abs(op-cl)>any)return false;
        return true;
    }
};