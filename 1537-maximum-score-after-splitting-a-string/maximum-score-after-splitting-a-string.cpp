class Solution {
public:
    int maxScore(string s) {
        int one=0;
        int n =s.size();

        for(int i=0; i<n; i++)
        {
            if(s[i]=='1')
              one++;
        }
        int res=0;
        int cone=0;
        for(int i=0; i<n-1; i++)
        {
             if(s[i]=='1')
                cone++;
             res=max(res, i+1-cone+one-cone);    
        }
        return res;
    }
};