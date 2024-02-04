class Solution {
public:
    bool comp(string& word, int curr)
    {
        int n = word.size();
        
        for(int i=curr; i<n; i++)
        {
            if(word[i]!=word[i-curr])
                return false;
            if(word[n-1-i]!=word[n-1-(i-curr)])
                return false;    
        }
        return true;
    }
    
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        int curr=k;
        
        
        while(curr<n)
        {
            if(comp(word, curr))
                return curr/k;
            curr+=k;
        }
        
        return curr/k;
        
    }
};