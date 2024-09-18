class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();

        for(int i=0; i<n/2; i++)
        {
            if(s[i]==s[n-1-i])
              continue;
            int k=i==0?1:0; 
            int j=i==n-1?n-2:n-1;

            while(k<j&&s[k]==s[j])
            {
                k++;
                j--;
                if(k==i)
                   k++;
                if(j==i)
                   j--;   
            }


            if(k>=j)
              return true;
            int c=n-1-i;
            k=c==0?1:0; 
            j=c==n-1?n-2:n-1;

            while(k<j&&s[k]==s[j])
            {
                k++;
                j--;
                if(k==c)
                   k++;
                if(j==c)
                   j--;   
            }  
            if(k>=j)
              return true;
            return false;  
        }
        return true;
    }
};