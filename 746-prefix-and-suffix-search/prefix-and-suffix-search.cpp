class Node
{
    public:
    set<int> p;
    Node* child[26];
};

class WordFilter {
public:
    Node* prefix = new Node();
    Node* suffix = new Node();

    void Insert(string & word, int j, bool pre)
    {
        Node* temp = pre ? prefix : suffix;
        for(int i=pre ? 0 : word.size()-1; pre ? i<word.size() : i>=0; pre ?i++ : i--)
        {
            int ind = word[i]-'a';
            if(temp->child[ind]==NULL)
               temp->child[ind]= new Node();
            temp->p.insert(j);
            temp=temp->child[ind];   
        }
        temp->p.insert(j);
    }

    set<int> find(string & word, bool pre)
    {
        Node* temp = pre ? prefix : suffix;
        set<int> s;
        for(int i=pre ? 0 : word.size()-1; pre ? i<word.size() : i>=0; pre ?i++ : i--)
        {
            int ind = word[i]-'a';
            if(temp->child[ind]==NULL)
               return s;
            temp=temp->child[ind];   
        }
        return temp->p;
    }


    WordFilter(vector<string>& words) {
        set<string> D;
        for(int i=words.size()-1; i>=0; i--)
        {
            if(D.find(words[i])!=D.end())
               continue;
            D.insert(words[i]);   
           Insert(words[i], i, true);
           Insert(words[i], i, false);
        }
    }
    
    int f(string pref, string suff) {
        set<int> a = find(pref, true);
        set<int> b = find(suff, false);
        int res=-1;
        for(auto it:b)
        {
            if(a.find(it)!=a.end())
              res= it;
        }
        return res;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */