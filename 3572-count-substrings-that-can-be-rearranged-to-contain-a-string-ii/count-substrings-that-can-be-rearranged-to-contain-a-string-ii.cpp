class Solution {
public:
    bool check(vector<int>& a, vector<int>& b)
    {
        for(int i=0; i<26; i++)
        {
            if(a[i]<b[i])
              return false;
        }
        return true;
    }

    // int binser(string& word1, vector<vector<int>>& DP,vector<int>&freq, int b, int i, int j)
    // {
    //     if(i==j)
    //        return i;
    //      else
    //      {
    //         int mid = i+(j-i)/2;
    //         vector<int> fr(26, 0);
    //         if(b==0)
    //            fr=DP[mid];
    //         else
    //           {
    //             for(int p=0; p<26; p++)
    //             {
    //                 fr[i]=DP[mid][p]-DP[b-1][p];
    //             }
    //             if(check(freq, fr))
    //             {
                    
    //             }
    //           }   
    //      }  
    // }

    long long validSubstringCount(string word1, string word2) {
        int m= word2.size();

        vector<int> freq(26, 0);
        int n = word1.size();

        //vector<vector<int>> DP(n, vector<int>(26, 0));
        for(int i=0; i<m; i++)
        {
            freq[word2[i]-'a']++;
        }
        // DP[0][word1[0]-'a']++;
        // for(int i=1; i<n; i++)
        // {
        //     for(int j=0; j<26; j++)
        //     {
        //        DP[i][j]=DP[i-1][j];
        //     }
        //     DP[i][word1[i]-'a']++;
        // }

        long long res=0;
        vector<int> f(26, 0);
        int j=0;
        for(int i=0; i<word1.size()-word2.size()+1; i++)
        {
             for(; j<n;j++)
             {
                f[word1[j]-'a']++;
                if(check(f, freq))
                {
                    res+=n-j;
                     f[word1[j]-'a']--;
                    break;
                }
             }
             f[word1[i]-'a']--;
        }
        return res;
    }
};