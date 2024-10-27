class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int n =s.size();
        int mod=pow(10, 9)+7;
        vector<long long> freq(26, 0);

        for(int i=0; i<n; i++)
        {
            freq[s[i]-'a']++;
        }

        long long len=n;

        while(t>0)
        {
            int z = freq[25];
            for(int i=25; i>=1; i--)
            {
                freq[i]=freq[i-1];
                freq[i]%=mod;
            }

            freq[0]=z;
            freq[0]%=mod;
            freq[1]+=z;
            freq[1]%=mod;
            
            len+=z;
            len%=mod;
            t--;
        }
        return len;


    }
};