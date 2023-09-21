    class Trie
    {
        public:
        Trie()
        {
            //CD.resize(26);
        }
        unordered_map<int, Trie*> CD;
    };

class Solution {
public:


    void add(vector<vector<char>>& board,Trie* t, int x, int y, int L)
    {
        if(x< 0 || y<0 || x == board.size() || y == board[0].size() || board[x][y]=='.' || L==0)
           return;  
        t->CD[board[x][y]-'a']=Add(t->CD[board[x][y]-'a'], board, x, y, L);   
    }
    Trie* Add(Trie* T, vector<vector<char>>& board, int x, int y, int L)
    {
     //   cout<<x<<"  "<<y<<endl;
            char ch = board[x][y];
            board[x][y]='.';
            if(T==NULL)
               T= new Trie();
           add(board, T, x+1, y, L-1);
           add(board, T, x-1, y, L-1);
           add(board, T, x, y+1,L-1);
           add(board, T, x, y-1, L-1);
           board[x][y]=ch;
           return T;
    }

    bool check(Trie* t, string& word, int i)
    {
        if(t==NULL)
          return false;
        if(i==word.size())
          return true;
        else
          return check(t->CD[word[i]-'a'], word, i+1);  
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
       vector<string> D;
         vector<Trie*> M(26);
         vector<int> len(26, 0);
         for(int i=0; i<words.size(); i++)
         {
             len[words[i][0]-'a']=max(len[words[i][0]-'a'], (int)words[i].size());
         }
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<m; k++)
                {
                   M[board[j][k]-'a']=Add(M[board[j][k]-'a'], board,j, k, len[board[j][k]-'a']+1);
                }
            }

        for(int i=0; i< words.size(); i++)
        {
           if(check(M[words[i][0]-'a'], words[i], 1))
             D.push_back(words[i]); 
            // cout<<i<<endl;
        }
        return D;
    }
};