class Solution {
public:
    int getdev(string s)
    {
        int res=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='1')
               res++;
        }
        return res;
    }
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev=getdev(bank[0]);
        int res=0;
        for(int i=1; i<n; i++)
        {
            int curr=getdev(bank[i]);
            res+=curr*prev;
           if(curr>0) 
            prev=curr;
        }
        return res;
    }
};