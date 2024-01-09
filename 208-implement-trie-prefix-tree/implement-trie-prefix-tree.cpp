class Node
{
    public:
    vector<Node*> next;
    bool ends=false;

    Node()
    {
        for(int i=0; i<26; i++)
        {
            next.push_back(NULL);
        }
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
            Node* temp;
            if(curr->next[ind]!=NULL)
               curr =curr->next[ind];
             else
             {
                 temp = new Node();
                 curr->next[ind]=temp;
                 curr=temp;
             }    
        }
        curr->ends=true;
    }
    
    bool search(string word) {
        int n=word.size();
        Node* curr=N;
        for(int i=0; i<n; i++)
        {
            int ind = word[i]-'a';
            if(curr->next[ind]!=NULL)
              {
                  curr=curr->next[ind];
              }
              else
                  return false;
        }
        return curr->ends;
    }
    
    bool startsWith(string word) {
        int n=word.size();
        Node* curr=N;
        for(int i=0; i<n; i++)
        {
            int ind = word[i]-'a';
            if(curr->next[ind]!=NULL)
              {
                  curr=curr->next[ind];
              }
              else
                  return false;
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