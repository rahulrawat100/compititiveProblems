class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        
        unordered_map<char, int> D;
        
        for(int i=0; i<n; i++)
        {
            D[s[i]]++;
        }
        unordered_map<int, int> E;
        
        priority_queue<int> F;
        
        for(auto it: D)
        {
            F.push(it.second);
        }
        
        int x = F.top();
        F.pop();
        E[x]=1;
        int count=0;
        while(!F.empty())
        {
            if(E.find(F.top())!=E.end())
            {
                int x = F.top();
                F.pop();
                if(x>1)
                F.push(x-1);
                count++;
            }
            else
            {
                 int x = F.top();
                  F.pop();
                 E[x]=1;
            }
        }
        return count;
    }
};

// b 4
// c=1
// e=1
// a=1    