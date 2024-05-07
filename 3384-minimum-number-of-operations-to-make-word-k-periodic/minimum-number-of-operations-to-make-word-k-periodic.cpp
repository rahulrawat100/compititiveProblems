class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        int rep=n/k;
        int i=0;
        int mx=1;
        unordered_map<string, int> freq;
        while(i<n)
        {
            string s="";
            for(int j=i; j<i+k;j++)
            {
                s+=word[j];
            }
            i+=k;
            freq[s]++;
            //cout<<s<<"  "<<freq[s]<<endl;
            mx=max(mx, freq[s]);
        }
        return rep-mx;


    }
};