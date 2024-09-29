class Solution {
public:
    vector<int> prevcons;
    int index(char ch)
    {
        if(ch=='a')
           return 0;
        else if(ch=='e')
           return 1;
        else if(ch=='i')
           return 2;      
        else if(ch=='o')
           return 3;
        else if(ch=='u')
           return 4;
        else
           return 5;      
    }

    bool check(string& word, vector<vector<int>>& freq,int k, int i, int j)
    {
            for(int p=0; p<5; p++)
            {
                if(freq[i][p]-(j==0?0:freq[j-1][p])==0)
                    return false;
            }
           if(freq[i][5]-(j==0?0:freq[j-1][5])>=k)
             return true;
           return false;  
    }

    long long getpos(string& word, vector<vector<int>>& freq,int k, int i,int x, int y)
    {
        if(x==y)
          return x;
        else
        {
            int mid = x+(y-x)/2;

            if(check(word, freq, k, i, mid))
            {
                if(check(word, freq, k, i, mid+1))
                   return getpos(word, freq, k, i, mid+1, y);
                else
                   return mid;   
            }
            else
            {
                if(check(word, freq, k, i, mid-1))
                   return mid-1;
                else   
                   return getpos(word, freq, k, i, x, mid-1);
            }
        }  

        
    }
    
    long long calc(string word, int k,vector<vector<int>>& freq)
    {
        long long res=0;
        
        int n =word.size();

        for(int i=0; i<n; i++)
        {
            if(!check(word, freq, k, i, 0)) continue;
            int j = getpos(word, freq,k, i, 0, i);
            if(freq[i][5]-(j==0?0:freq[j-1][5])>k)
              continue;
            int l=j;
             j = prevcons[j];
             //cout<<i<<"   "<<l<<"     "<<j<<endl;
             res+=l-j;
        }
        return res;
    }

    long long countOfSubstrings(string word, int k) {
        int n =word.size();
        vector<int> pc(n);

        pc[0]=-1;

        for(int i=1; i<n; i++)
        {
            if(index(word[i-1])==5)
               pc[i]=i-1;
            else
               pc[i]=pc[i-1];   
        }
        prevcons=pc;
        vector<vector<int>> freq(n, vector<int>(6, 0));
        freq[0][index(word[0])]++;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<6; j++)
            {
                freq[i][j]=freq[i-1][j];
            }
            freq[i][index(word[i])]++;
        }

        return calc(word, k, freq);
    }
};