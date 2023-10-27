class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans=1;
        string res="";
        for(int i=0; i<n; i++)
        {
            int x=i-1;
            int y=i+1;
            string temp="";
             temp+=s[i];
            while(x>=0&&y<n)
            {
                if(s[x]!=s[y])
                   break;
                   temp=s[x]+temp+s[y];
                x--;
                y++;   
            }
            if(temp.size()>res.size())
            {
                res= temp;
            }
            x=i;
            y=i+1;
             temp="";  
            while(x>=0&&y<n)
            {
                if(s[x]!=s[y])
                   break;
                temp=s[x]+temp+s[y];   
                x--;
                y++;   
            }
            if(temp.size()>res.size())
               res=temp;
        }
        return res;
    }
};