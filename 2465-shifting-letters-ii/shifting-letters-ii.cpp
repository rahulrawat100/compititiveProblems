class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        unordered_map<int, int> mpi;
        unordered_map<int, int> mpd;

        int m =shifts.size();

        for(int i=0; i<m ;i++)
        {
           if(shifts[i][2]==1)
            {
              mpi[shifts[i][0]]++;
              mpi[shifts[i][0]]=mpi[shifts[i][0]];
              mpi[shifts[i][1]+1]--;
            }
            else
           {
              mpd[shifts[i][0]]++;
              mpd[shifts[i][1]+1]--;
            }
        }
        
        int curr=0;
        for(int i=0; i<s.size(); i++)
        {
            int ind = s[i]-'a';
            curr+=mpi[i];
            ind+=curr;   
            ind=(ind)%26;
            //cout<<ind<<endl;
            s[i]=(char)(ind+'a');   
        }

        curr=0;
        for(int i=0; i<s.size(); i++)
        {
            int ind = s[i]-'a';
            curr+=mpd[i];
            curr%=26;
            ind-=curr;   
            ind=(ind+26)%26;
            //cout<<ind<<endl;
            s[i]=(char)(ind+'a');   
        }
        return s;
    }
};