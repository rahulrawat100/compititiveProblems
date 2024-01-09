class Node
{
    public:
    Node *next[26]{};
    bool ends;

    Node()
    {
        ends=false;
    }
};

class Trie {
public:
    Node* N;
    Trie() {
        N= new Node();
    }
    
    void insert(string word) {
        int n = word.size();
        Node* curr=N;
        for(int i=0; i<n; i++)
        {
            int ind = word[i]-'a';
            if(curr->next[ind] == NULL)
               curr->next[ind]=new Node();
            curr=  curr->next[ind];    
        }
        curr->ends=true;
    }
    
    bool search(string word) {
        int n=word.size();
        Node* curr=N;
        for(int i=0; i<n; i++)
        {
            int ind = word[i]-'a';
            if(curr->next[ind]==nullptr)
               return false;
            curr=curr->next[ind];   
        }
        return curr->ends;
    }
    
    bool startsWith(string word) {
        int n=word.size();
        Node* curr=N;
        for(int i=0; i<n; i++)
        {
            int ind = word[i]-'a';
            if(curr->next[ind]==nullptr)
               return false;
            curr=curr->next[ind];  
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */