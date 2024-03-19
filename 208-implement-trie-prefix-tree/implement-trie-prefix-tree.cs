public class Node
{
    public Node[] child = new Node[26];
    public bool end;
}

public class Trie {
    Node root = new Node();
    public Trie() {
        
    }
    
    public void Insert(string word) {
        int n = word.Count();
        Node curr = root;
        for(int i=0; i<n; i++)
        {
            int ind = word[i]-'a';
            if(curr.child[ind]==null)
              curr.child[ind]=new Node();
            curr=curr.child[ind];  
        }
        curr.end=true;
    }
    
    public bool Search(string word) {
        Node curr = root;
                int n = word.Count();
        for(int i=0; i<n; i++)
        {
            int ind = word[i]-'a';
            if(curr.child[ind]==null)
              return false;
            curr=curr.child[ind];  
        }
        return curr.end;
    }
    
    public bool StartsWith(string word) {
        Node curr = root;
                int n = word.Count();
        for(int i=0; i<n; i++)
        {
            int ind = word[i]-'a';
            if(curr.child[ind]==null)
              return false;
            curr=curr.child[ind];  
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.Insert(word);
 * bool param_2 = obj.Search(word);
 * bool param_3 = obj.StartsWith(prefix);
 */