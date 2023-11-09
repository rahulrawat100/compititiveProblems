class Solution {
public:    
    int countHomogenous(string s) {    
        int n = s.size();
        int res=0;
        for(int i=0; i<n; i++)
        {
            int j=i;
            for(; j<n; j++)
            {
                if(s[j]!=s[i])
                    break;
                res+=(j-i+1);  
                res = res%1000000007;                
            }
            i=j-1;
        }
        return res;
            
    }
};